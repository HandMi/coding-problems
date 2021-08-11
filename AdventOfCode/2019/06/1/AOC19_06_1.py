
import sys
from collections import defaultdict


class OrbitalMap:
    def __init__(self, orbits):
        self.orbits = orbits
        self.orbit_count = defaultdict(int)

    def dfs(self, key):
        if key not in self.orbits:
            self.orbit_count[key] = 0
        else:
            for planet in self.orbits[key]:
                self.dfs(planet)
            self.orbit_count[key] = sum(
                self.orbit_count[planet] for planet in self.orbits[key]) + len(self.orbits[key])

    def count_orbits(self):
        self.dfs('COM')
        return sum(self.orbit_count[key] for key in self.orbit_count)


if __name__ == '__main__':
    input_file = open(sys.argv[1])
    orbits = defaultdict(list)
    for line in input_file:
        planets = line.rstrip('\n').split(')')
        orbits[planets[0]].append(planets[1])

    map = OrbitalMap(orbits)
    print(map.count_orbits())
