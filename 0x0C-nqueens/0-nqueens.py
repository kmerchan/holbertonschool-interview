#!/usr/bin/python3
"""
Solves the N Queens puzzle for NxN chessboard
finds placement of N number of non-attacking queens
"""

import sys


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    N = sys.argv[1]
    if type(N) is not int:
        print("N must be a number")
        exit(1)
    if N < 4:
        print("N must be at least 4")
        exit(1)
