
import sys


def execute(intcode, noun, verb):
    intcode[1] = noun
    intcode[2] = verb

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
    for noun in range(100):
        for verb in range(100):
            testcode = intcode.copy()
            execute(testcode, noun, verb)
            if(testcode[0] == 19690720):
                print(100 * noun + verb)
                break
