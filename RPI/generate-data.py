#!/usr/bin/env python3
"""
Generate tokens and weights for QLLA testing and benchmarking.
"""

import numpy as np
import argparse

def generate_and_save(in_dim, out_dim):
    tokens = np.random.randint(0, 65536, size=in_dim, dtype=np.uint16)
    weights = np.random.randint(0, 65536, size=(out_dim, in_dim), dtype=np.uint16)

    np.savetxt("token_vals.txt", tokens, fmt="%d")
    np.savetxt("weight_vals.txt", weights.flatten(), fmt="%d")

    return tokens, weights

def main():
    p = argparse.ArgumentParser()
    p.add_argument("--in-dim", type=int, default=256)
    p.add_argument("--out-dim", type=int, default=256)
    args = p.parse_args()

    tokens, weights = generate_and_save(args.in_dim, args.out_dim)
    print(f"Generated {args.in_dim}-input x {args.out_dim}-output test case.")

if __name__ == "__main__":
    main()
