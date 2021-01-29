#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics
"""

from sys import exit, stdin
from signal import signal, SIGINT

if __name__ == "__main__":
    total_size = 0
    status_codes = {}
    list_status_codes = [
        "200", "301", "400", "401", "403", "404", "405", "500"]
    for status in list_status_codes:
        status_codes[status] = 0
    count = 0
    for line in stdin:
        args = line.split(" ")
        status_codes[args[7]] += 1
        if args[8][-1] == '\n':
            args[8][:-1]
        total_size += int(args[8])
        if count % 10 == 0 and count != 0:
            print("File size: {}".format(total_size))
            for status in sorted(status_codes.keys()):
                if status_codes[status] != 0:
                    print("{}: {}".format(status, status_codes[status]))
        count += 1
    if count % 10 != 0:
        print("File size: {}".format(total_size))
        for status in status_codes.sorted():
            if status_codes[status] != 0:
                print("{}: {}".format(status, status_codes[status]))

# def signal_handler(sig, frame):
    # """
    # catches signal CTRL-C and prints stats
    # """
    # print("File size: {}".format(total_size))
    # for status in status_codes.sorted():
        # if status_codes[status] != 0:
            # print("{}: {}".format(status, status_codes[status]))
    # exit(0)
