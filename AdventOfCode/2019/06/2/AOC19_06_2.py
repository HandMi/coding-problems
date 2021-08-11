
import sys
from collections import defaultdict


class OrbitalMap:
    def __init__(self, orbits):
        self.orbits = orbits
        self.orbit_count = defaultdict(int)

    def search(self, node, root, distance):
        distance += 1
        if(node == 'SAN'):
            print(distance-3)
        else:
            for neighbor in self.orbits[node]:
                if neighbor != root:
                    self.search(neighbor, node, distance)


if __name__ == '__main__':
    input_file = open(sys.argv[1])
    orbits = defaultdict(list)
    for line in input_file:
        planets = line.rstrip('\n').split(')')
        orbits[planets[0]].append(planets[1])
        orbits[planets[1]].append(planets[0])

    map = OrbitalMap(orbits)
    map.search('YOU', '', 0)
