
import sys


def execute(intcode):
    intcode[1] = 12
    intcode[2] = 2

    it = 0
    while intcode[it] != 99:
        if intcode[it] == 1:
            intcode[intcode[it+3]] = intcode[intcode[it+1]] + \
                intcode[intcode[it+2]]
        if intcode[it] == 2:
            intcode[intcode[it+3]] = intcode[intcode[it+1]] * \
                intcode[intcode[it+2]]
        it = it + 4


if __name__ == '__main__':
    input_file = open(sys.argv[1])
    intcode = [int(x) for x in input_file.read().split(',')]
    execute(intcode)
    print(intcode[0])
