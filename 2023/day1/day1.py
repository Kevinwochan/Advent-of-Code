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
}

def part_one(lines):
    sum = 0
    for line in lines:
        digits = [c for c in line if c.isdigit()]
        calibration_value = int(str(digits[0]) + str(digits[-1]))
        sum += calibration_value
    print(sum)

#lines=['three2fiveonexrllxsvfive']

def part_two(lines):
    sum = 0
    for line in lines:
        digits = []
        # find word digits
        for number, value in numbers.items():
            index = line.find(number)
            while index != -1:
                digits.append({'index': index, 'value': value})
                index = line.find(number, index+1)
                if index > -1:
                    digits.append({'index': index, 'value': value})
                    print(line[index], number, )
        # find numerical digits
        for index, c in enumerate(line, 0):
            if c.isdigit():
                digits.append({'index': index, 'value': int(c)}) 
        digits = sorted(digits, key= lambda x: x['index'])
        print(digits)
        calibration_value = int(str(digits[0]['value']) + str(digits[-1]['value']))
        sum += calibration_value
        print(calibration_value)
    return sum

print(part_two(lines))