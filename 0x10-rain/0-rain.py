#!/usr/bin/python3
"""
Defines a function that calculates how much rainwater will be retained
given a list of non-negative integers that represents walls of width 1
"""


def rain(walls):
    """
    Calculates rainwater retention given list representing walls

    parameters:
        walls [list of non-negative ints]:
            represents walls of width 1
            assume the ends of the list are not walls, will not retain water

    returns:
        [int]: representing the total amount of rainwater retained
            if walls list is empty, returns 0
    """
    if type(walls) is not list or walls is []:
        return 0
    for i in walls:
        if i < 0:
            return 0
    return sum(walls[1:-1])
