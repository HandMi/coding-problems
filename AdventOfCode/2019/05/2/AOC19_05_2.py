
import sys


class IntCodeComputer:
    def __init__(self):
        self.instructions = {1: self.add,
                             2: self.mult, 3: self.read, 4: self.out, 5: self.jump_if_true,
                             6: self.jump_if_false, 7: self.less_than, 8: self.equals}

    def parse(self, opcode):
        instruction = opcode % 100
        modes = int((opcode-instruction)/100)
        mode_list = []
        for i in range(3):
            mode_list.append(modes % 10)
            modes = int(modes/10)
        return instruction, mode_list

    def get_params(self, code, pos, mode, number_of_parameters):
        params = []
        for i in range(number_of_parameters):
            if(mode[i]):
                params.append(code[pos+i+1])
            else:
                params.append(code[code[pos+i+1]])
        return params

    def add(self, code, pos, mode):
        p = self.get_params(code, pos, mode, 2)
        code[code[pos+3]] = p[0] + p[1]
        return pos+4

    def mult(self, code, pos, mode):
        p = self.get_params(code, pos, mode, 2)
        code[code[pos+3]] = p[0] * p[1]
        return pos+4

    def read(self, code, pos, mode):
        x = input()
        code[code[pos+1]] = int(x)
        return pos+2

    def out(self, code, pos, mode):
        p = self.get_params(code, pos, mode, 1)
        print(p[0])
        return pos+2

    def jump_if_true(self, code, pos, mode):
        p = self.get_params(code, pos, mode, 2)
        if (p[0] != 0):
            return p[1]
        return pos+3

    def jump_if_false(self, code, pos, mode):
        p = self.get_params(code, pos, mode, 2)
        if (p[0] == 0):
            return p[1]
        return pos+3

    def less_than(self, code, pos, mode):
        p = self.get_params(code, pos, mode, 2)
        if(p[0] < p[1]):
            code[code[pos+3]] = 1
        else:
            code[code[pos+3]] = 0
        return pos+4

    def equals(self, code, pos, mode):
        p = self.get_params(code, pos, mode, 2)
        if(p[0] == p[1]):
            code[code[pos+3]] = 1
        else:
            code[code[pos+3]] = 0
        return pos+4

    def execute(self, code):
        pos = 0
        while(code[pos] != 99 and pos < len(code)):
            instruction, modes = self.parse(code[pos])
            pos = self.instructions[instruction](code, pos, modes)


if __name__ == '__main__':
    input_file = open(sys.argv[1])
    intcode = [int(x) for x in input_file.read().split(',')]
    computer = IntCodeComputer()
    computer.execute(intcode)
