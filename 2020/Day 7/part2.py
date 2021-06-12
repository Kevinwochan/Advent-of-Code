#!/usr/bin/python3


def is_solved(solved, bags):
    for bag in bags:
        if bag['pattern'] not in solved:
            return False
    return True


def solve_bag(bags, solved):
    num_bags = 0
    for bag in bags:
        num_bags += (bag['amount'] * solved[bag['pattern']]) + bag['amount']
    return num_bags


lines = []
with open('input.txt') as f:
    lines = f.readlines()

# Priority Queue to bild results from the foundational bags
relationships = {}  # table[bag] = [{'amount', 'pattern'}]
dependencies = {}  # table[bag] = ['pattern1']
solved = {}  # table[bag] = num
q = []

for line in lines:
    if "contain no other bags" in line:
        pattern = ' '.join(line.split(' ')[:2]).strip()
        solved[pattern] = 0
        continue
    # Parse the line
    holder, contents_unparsed = line.strip().split(' bags contain ')
    contents = contents_unparsed.replace(' bags',
                                         '').replace(' bag', '').replace(
                                             '.', '').split(', ')
    inner_bags = []
    for bag in contents:
        pattern = ' '.join(bag.split(' ')[1:])
        inner_bags.append({
            'amount': int(bag.split(' ')[0]),
            'pattern': pattern.strip()
        })
        if pattern not in dependencies:
            dependencies[pattern] = [holder]
        dependencies[pattern].append(holder)

    relationships[holder] = inner_bags

q = [pattern for pattern in solved]  # a queue of patterns to be solved

while len(q) > 0 and 'shiny gold' not in solved:
    pattern = q.pop(0)
    for bag in dependencies[pattern]:
        if is_solved(solved, relationships[bag]):
            solved[bag] = solve_bag(relationships[bag], solved)
            q.append(bag)
print(solved)
print(solved['shiny gold'])
