
import sys
from itertools import permutations
import copy

class IntCodeComputer:
    def __init__(self, code, input = []):
        self.instructions = {1: self.add,
                             2: self.mult, 3: self.read, 4: self.out, 5: self.jump_if_true,
                             6: self.jump_if_false, 7: self.less_than, 8: self.equals}
        self.code = copy.deepcopy(code)
        self.input = input
        self.input_ptr = 0
        self.output = 0
        self.pos = 0
        self.wait = False
        self.halt = False

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
        if(self.input_ptr < len(self.input)):
            x = self.input[self.input_ptr]
            self.input_ptr+=1
        else:
            self.pos = pos
            self.wait = True
            return pos
        code[code[pos+1]] = int(x)
        return pos+2

    def out(self, code, pos, mode):
        p = self.get_params(code, pos, mode, 1)
        self.output = p[0]
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
        pos = self.pos
        self.wait = False
        while(pos < len(code) and not self.wait and not self.halt):
            instruction, modes = self.parse(code[pos])
            pos = self.instructions[instruction](code, pos, modes)
            if(code[pos] == 99):
                self.halt = True

    def cont(self, inpt):
        self.input.append(inpt)
        self.execute(self.code)


if __name__ == '__main__':
    input_file = open(sys.argv[1])
    intcode = [int(x) for x in input_file.read().split(',')]
    result = 0
    perms = permutations([5, 6, 7, 8, 9])
    for perm in list(perms):
        computers = [IntCodeComputer(intcode, [phase]) for phase in perm]
        signal = 0
        i = 0
        while(not computers[i].halt):
            computers[i].cont(signal)
            signal = computers[i].output
            i = i + 1 if i < len(computers)-1 else 0
        result = max(signal,result)

    print(result)
