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

    # checks if given valid list of boxes
    if type(boxes) is not list or len(boxes) < 1:
        return False
    # checks that all boxes contain a valid list of keys (empty boxes are OK)
    # keys can be assumed to be positive integers, type will be confirmed later
    for box in boxes:
        if type(box) is not list:
            return False
    # creates a copy of boxes to not affect the original list of lists
    copyBoxes = deepcopy(boxes)
    # calls unlockBox() method to open box 0
    # unlockBox() will recursively open any boxes with keys from the opened box
    keys_list = [0]
    while len(keys_list) > 0:
        key = keys_list[0]
        keys_list = keys_list[1:]
        if type(key) is not int or key < 0:
            # if key is invalid, move to next valid key
            continue
        # mark that the box has been opened by appeneding a -1 flag
        # since all keys are pos ints, -1 will not be mistaken for a valid key
        copyBoxes[key].append(-1)
        # loop through any new keys found in the recently opened box
        # save new keys to keys_list to potentially open more boxes
        for new_key in copyBoxes[key]:
            if new_key >= len(copyBoxes):
                # if new key is out of range of the available boxes, continue
                continue
            if -1 in copyBoxes[new_key] or new_key in keys_list:
                # if the box has previously been opened, continue
                continue
            # update the list of availble key
            keys_list.append(new_key)
    # after opening all possible boxes, check that total boxes have been opened
    # opened boxes are noted with a -1 flag
    for box in copyBoxes:
        if -1 not in box:
            # if a box is missing the -1 flag, it was not unlocked
            return False
    # returns true if all boxes in the previous loop were indicated as unlocked
    return True
