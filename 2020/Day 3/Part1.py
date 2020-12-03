#!/usr/bin/python3.8

import sys

map = None
with open('input.txt') as f:
    map = f.readlines()

if map == None:
    print('could not read file')
    sys.exit(1)

# Map is a list of strings

tree_count = 0
col = 3
for row in range(1, len(map)):
    row = list(map[row])
    if row[col] == "#":
        row[col] = 'X'
        tree_count += 1
    else:
        row[col] = 'O'
    print(row)
    col = (col+3)%(len(row)-1)

print(f'You hit {tree_count} trees')