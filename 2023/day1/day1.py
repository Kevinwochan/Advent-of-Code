#!/usr/bin/python3.8

import sys

lines = None
with open('input.txt') as f:
    lines = f.readlines()

if lines == None:
    print('could not read file')
    sys.exit(1)

numbers = {
    'one': 1,
    'two': 2,
    'three': 3,
    'four': 4,
    'five': 5,
    'six': 6,
    'seven': 7,
    'eight': 8,
    'nine': 9,
    'ten': 10
}

def part_one(lines):
    sum = 0
    for line in lines:
        digits = [c for c in line if c.isdigit()]
        calibration_value = int(str(digits[0]) + str(digits[-1]))
        sum += calibration_value

    print(sum)

sum = 0
for line in lines:
    digits = []
    for number, value in numbers.items():
        index = line.find(number)
        if index > -1:
            digits.append({'index': index, 'value': number})
    digits = sorted(digits, key= lambda x: x['index'])
    calibration_value = int(str(digits[0]['value']) + str(digits[-1]['value']))
    sum += calibration_value

print(sum)