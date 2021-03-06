#!/usr/bin/python3
"""
Defines a method that calculates the fewest number of operations needed
to result in exactly n copies of a character in a text file, whose
only operations are Copy All and Paste
"""


def minOperations(n):
    """
    calculates the fewest number of operations needed
    to result in exactly n copies of a character in a text file,
    whose only operations are Copy All and Paste

    parameters:
        n [int]: number of copies of the character desired

    returns:
        the minimum number of operations needed to result in n characters
        or 0 if n is impossible to achieve
    """
    if type(n) is not int or n <= 1:
        return 0
    primes = [2, 3]
    summation = []
    divisor = 2
    while (n % divisor) is 0 and (n // divisor) is not 1:
        summation.append(divisor)
        n = n // divisor
    divisor = 3
    while n > divisor:
        while (n % divisor) is 0 and (n // divisor) is not 1:
            summation.append(divisor)
            n = n // divisor
        divisor += 2
        while True:
            for prime in primes:
                if (divisor % prime) is 0:
                    divisor += 2
                    break
            else:
                primes.append(divisor)
                break
    summation.append(n)
    return sum(summation)
