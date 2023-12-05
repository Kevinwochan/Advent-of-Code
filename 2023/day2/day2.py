#!/usr/bin/python3.8

import sys

lines = None
with open('input.txt') as f:
    lines = f.readlines()

if lines == None:
    print('could not read file')
    sys.exit(1)


'''
Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
'''

def is_game_set_valid(game_set):
    for cube in game_set.split(', '):
        [cube_count, cube_color] = cube.split(' ')
        if int(cube_count) > bag[cube_color.strip()]:
            return False
    return True

def part_one(lines):
    bag = {'red': 12, 'green': 13, 'blue': 14}
    possible_game_sum = 0
    for line in lines:
        [game_id, games] = line.split(': ')
        game_sets = games.split('; ')
        if all(map(is_game_set_valid, game_sets)):
            possible_game_sum += int(game_id.replace('Game ',''))
    print(possible_game_sum)



def part_two(lines):
    cube_power_sum = 0
    for line in lines:
        [game_id, games] = line.split(': ')
        min_bag = {'red': 0, 'green': 0, 'blue': 0}
        game_sets = games.split('; ')
        for game_set in game_sets:
            for cube in game_set.split(', '):
                [cube_count, cube_color] = cube.split(' ')
                min_bag[cube_color.strip()] = max(min_bag[cube_color.strip()], int(cube_count))
        cube_power = min_bag['red'] * min_bag['green'] * min_bag['blue']
        cube_power_sum += cube_power
    print(cube_power_sum)

part_two(lines)