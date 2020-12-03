#!/usr/bin/python3.8

import sys

map = None
with open('input.txt') as f:
    map = f.readlines()

if map == None:
    print('could not read file')
    sys.exit(1)

# Map is a list of strings
def treeCount(right, down):
    tree_count = 0
    col = right
    for row in range(down, len(map), down):
        row = list(map[row])
        if row[col] == "#":
            row[col] = 'X'
            tree_count += 1
        else:
            row[col] = 'O'
        print(row)
        col = (col+right)%(len(row)-1)
    print(f'You hit {tree_count} trees')
    return tree_count

print(treeCount(1,1) * treeCount(3, 1)* treeCount(5, 1) * treeCount(7,1) * treeCount(1, 2))
