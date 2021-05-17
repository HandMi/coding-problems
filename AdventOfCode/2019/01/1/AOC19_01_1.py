
import sys
from math import floor

def fuel(mass):
    return floor(mass/3) - 2

if __name__ == '__main__':
    input_file = open(sys.argv[1])
    fuel_usage = [fuel(int(m)) for m in input_file.readlines()]
    print(sum(fuel_usage))
