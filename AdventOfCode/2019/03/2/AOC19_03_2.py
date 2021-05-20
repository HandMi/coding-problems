import fileinput
from sys import maxsize


def trace(wire):
    x, y, n = 0, 0, 0
    trace = {}
    for segment in wire:
        for _ in range(segment[1]):
            n += 1
            if(segment[0] == 'R'):
                x += 1
            elif(segment[0] == 'L'):
                x -= 1
            elif(segment[0] == 'U'):
                y += 1
            elif(segment[0] == 'D'):
                y -= 1
            trace[(x, y)] = n
    return trace


def find_fewest_steps(trace, wire):
    dist = maxsize
    x, y, n = 0, 0, 0
    for segment in wire:
        for _ in range(segment[1]):
            n += 1
            if(segment[0] == 'R'):
                x += 1
            elif(segment[0] == 'L'):
                x -= 1
            elif(segment[0] == 'U'):
                y += 1
            elif(segment[0] == 'D'):
                y -= 1
            if (x, y) in trace:
                dist = min(trace[(x, y)] + n, dist)
    return dist


if __name__ == '__main__':
    wires = [[[x[0], int(x[1:])]
              for x in wire.split(',')] for wire in fileinput.input()]
    trace1 = trace(wires[0])
    dist = find_fewest_steps(trace1, wires[1])
    print(dist)
