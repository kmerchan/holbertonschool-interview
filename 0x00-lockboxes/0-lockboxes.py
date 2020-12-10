#!/usr/bin/python3
""" defines method to solve lockboxes problem """


def canUnlockAll(boxes):
    """
    determines if all boxes can be unlocked

    parameters:
        boxes (list): list of list representing boxes and any keys inside
            There are n number of boxes, labeled sequentially starting at 0.
            Keys with the same number as a box opens that box.
            All keys can be assumed to be positive integers.
            There can be boxes without keys and keys without boxes.
            The first box boxes[0] is the only unlocked box initially.

    returns:
        True, if all boxes can be unlocked
        False, if one or more boxes cannot be unlocked
    """
    from copy import deepcopy

    if type(boxes) is not list or len(boxes) < 1:
        return False
    for box in boxes:
        if type(box) is not list:
            return False
    unlockedBoxes = deepcopy(boxes)
    unlockedBoxes = unlockBox(unlockedBoxes, 0)
    for box in unlockedBoxes:
        if -1 not in box:
            return False
    return True


def unlockBox(boxes, key):
    """
    unlocks the box corresponding to a given key, recursively

    parameters:
        boxes (list): list of list representing the boxes and any keys inside
        key (int): the index of the box to unlock

    returns:
        boxes, with marker (-1) indicating that the box has been opened
    """
    if type(key) is not int or key is -1:
        return boxes
    if key >= len(boxes):
        return boxes
    if -1 in boxes[key]:
        return boxes
    boxes[key].append(-1)
    for new_key in boxes[key]:
        boxes = unlockBox(boxes, new_key)
    return boxes
