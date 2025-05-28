#!/usr/bin/env python3
"""
benchmark_cpu_qlla.py

Benchmark a quantized linear layer on CPU using the same token and weight data
used for your FPGA-based Quantized Linear Layer Accelerator.

Usage:
  python3 benchmark_cpu_qlla.py \
    --tokens token_vals.txt \
    --weights weight_vals.txt
"""

import numpy as np
import time
import argparse

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
    p.add_argument('--tokens', required=True,
                   help='Path to text file listing tokens')
    p.add_argument('--weights', required=True,
                   help='Path to text file listing weights')
    p.add_argument('--repeats', type=int, default=100,
                   help='Number of repetitions for timing')
    args = p.parse_args()

    # Load inputs
    tokens = np.array(read_values_file(args.tokens), dtype=np.uint16)
    weights = np.array(read_values_file(args.weights), dtype=np.uint16)

    # Infer matrix dimensions
    token_len = len(tokens)
    weight_len = len(weights)
    if weight_len % token_len != 0:
        raise ValueError(f"Weight length ({weight_len}) must be a multiple of token length ({token_len})")

    out_dim = weight_len // token_len
    W = weights.reshape((out_dim, token_len))  # shape: (out_dim, in_dim)
    x = tokens  # shape: (in_dim,)

    print(f"Performing CPU quantized matmul: ({out_dim}x{token_len}) * ({token_len})")
    times = []
    for _ in range(args.repeats):
        start = time.perf_counter()
        y = np.dot(W.astype(np.uint32), x.astype(np.uint32))
        end = time.perf_counter()
        times.append((end - start) * 1e6)  # µs

    avg_time = np.mean(times)
    print(f"Output (first 10 values): {y[:10]}")
    print(f"Average time over {args.repeats} runs: {avg_time:.2f} µs")

if __name__ == '__main__':
    main()
