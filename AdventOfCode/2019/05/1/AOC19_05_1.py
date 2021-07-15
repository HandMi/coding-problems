
import sys


class IntCodeComputer:
    def __init__(self):
        self.instructions = {1: self.add,
                             2: self.mult, 3: self.read, 4: self.out}

    def parse(self, opcode):
        instruction = opcode % 100
        modes = int((opcode-instruction)/100)
        mode_list = []
        for i in range(3):
            mode_list.append(modes % 10)
            modes = int(modes/10)
        return instruction, mode_list

    def add(self, code, pos, mode):
        if(mode[0]):
            x = code[pos+1]
        else:
            x = code[code[pos+1]]
        if(mode[1]):
            y = code[pos+2]
        else:
            y = code[code[pos+2]]
        code[code[pos+3]] = x + y
        return 4

    def mult(self, code, pos, mode):
        if(mode[0]):
            x = code[pos+1]
        else:
            x = code[code[pos+1]]
        if(mode[1]):
            y = code[pos+2]
        else:
            y = code[code[pos+2]]
        code[code[pos+3]] = x * y
        return 4

    def read(self, code, pos, mode):
        x = input()
        code[code[pos+1]] = int(x)
        return 2

    def out(self, code, pos, mode):
        print(code[code[pos+1]])
        return 2

    def execute(self, code):
        pos = 0
        while(code[pos] != 99 and pos < len(code)):
            instruction, modes = self.parse(code[pos])
            pos += self.instructions[instruction](code, pos, modes)


if __name__ == '__main__':
    input_file = open(sys.argv[1])
    intcode = [int(x) for x in input_file.read().split(',')]
    computer = IntCodeComputer()
    computer.execute(intcode)
