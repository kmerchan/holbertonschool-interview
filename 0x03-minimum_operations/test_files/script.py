#!/usr/bin/python3

from random import randint
from time import time
minOperations = __import__('0-minoperations').minOperations
minOpsStrict = __import__('0-minoperations-strict_primes').minOperations

n = 0
while n < 5:
    random_num = randint(0, 99999999)
    start1 = time()
    result1 = minOperations(random_num)
    stop1 = time()
    print("n = " + str(random_num), end="\t-->\t")
    start2 = time()
    result2 = minOpsStrict(random_num)
    stop2 = time()
    if result1 != result2:
        print('we found a fail!')
        print("\nresult1: ", result1, "\tresult2: ", result2)
        break
    print(result1)
    time_diff1 = stop1 - start1
    time_diff2 = stop2 - start2
    print("time1: ", time_diff1, "\ttime2: ", time_diff2)
    n += 1
