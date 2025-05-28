#!/usr/bin/env python3
"""
rpi_uart_loader.py

Send tokens and weights over UART to your FPGA’s uart_rx + spi_command_controller chain.

Usage:
  python3 rpi_uart_loader.py \
    --port /dev/serial0 \
    --baud 115200 \
    --token-base 0 --tokens token_vals.txt \
    --weight-base 0 --weights weight_vals.txt \
    --start

Where token_vals.txt and weight_vals.txt are plain text files,
one 16-bit unsigned integer per line.
"""

import serial
import time
import struct
import argparse

# Command codes from spi_command_controller
CMD_LOAD_TOKEN = 0x01
CMD_LOAD_WEIGHT = 0x02
CMD_START_MATMUL = 0x03

def open_serial(port, baud):
    ser = serial.Serial(port=port, baudrate=baud, timeout=1.0)
    # give FPGA uart_rx time to come out of reset
    time.sleep(0.1)
    return ser

def send_bytes(ser, data: bytes, delay=0.0001):
    """Send each byte with a tiny delay to ensure FPGA can sample it."""
    for b in data:
        ser.write(bytes([b]))
        time.sleep(delay)

def load_block(ser, cmd, base_addr, values):
    """
    Send a LOAD_TOKEN or LOAD_WEIGHT block:
      [CMD] [ADDR_H] [ADDR_L] [LEN_H] [LEN_L] [DATA_H,DATA_L] * LEN
    """
    length = len(values)
    if length == 0:
        return
    header = struct.pack('>B H H',
                         cmd,
                         base_addr & 0xFFFF,
                         length & 0xFFFF)
    # header layout is B H H, but spi_command_controller reads:
    #   byte0: CMD
    #   byte1: ADDR_H
    #   byte2: ADDR_L
    #   byte3: LEN_H
    #   byte4: LEN_L
    send_bytes(ser, header)
    # now send each 16-bit word big-endian
    for val in values:
        hi = (val >> 8) & 0xFF
        lo = val & 0xFF
        send_bytes(ser, bytes([hi, lo]))

def start_matmul(ser):
    """Send the START_MATMUL command (0x03)."""
    send_bytes(ser, bytes([CMD_START_MATMUL]))

def read_values_file(path):
    """Read one integer per line from a text file."""
    vals = []
    with open(path, 'r') as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith('#'):
                continue
            vals.append(int(line, 0))
    return vals

def main():
    p = argparse.ArgumentParser()
    p.add_argument('--port',    default='/dev/serial0',
                   help='UART device (e.g. /dev/serial0)')
    p.add_argument('--baud',    type=int, default=115200)
    p.add_argument('--token-base', type=int, default=0,
                   help='BRAM base address for tokens')
    p.add_argument('--tokens',   type=str, required=True,
                   help='Path to text file listing tokens')
    p.add_argument('--weight-base', type=int, default=0,
                   help='BRAM base address for weights')
    p.add_argument('--weights',    type=str, required=True,
                   help='Path to text file listing weights')
    p.add_argument('--no-start', dest='start', action='store_false',
                   help="Don't send START_MATMUL at end")
    args = p.parse_args()

    # load data files
    token_vals  = read_values_file(args.tokens)
    weight_vals = read_values_file(args.weights)

    ser = open_serial(args.port, args.baud)
    print(f"Opened {args.port} @ {args.baud} baud")

    print(f"Loading {len(token_vals)} tokens @ base {args.token_base}...")
    load_block(ser, CMD_LOAD_TOKEN, args.token_base, token_vals)
    print("Tokens loaded.")

    print(f"Loading {len(weight_vals)} weights @ base {args.weight_base}...")
    load_block(ser, CMD_LOAD_WEIGHT, args.weight_base, weight_vals)
    print("Weights loaded.")

    if args.start:
        print("Starting matrix multiply...")
        start_matmul(ser)
        print("Start command sent.")

    ser.close()
    print("Done.")

if __name__ == "__main__":
    main()