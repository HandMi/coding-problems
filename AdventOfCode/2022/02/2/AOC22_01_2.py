import sys

if __name__ == "__main__":
    input_file = open(sys.argv[1])
    score = 0
    for line in input_file.readlines():
        line = line.strip().split(" ")
        input_file = open(sys.argv[1])
        a = ord(line[0]) - ord("A")
        b = line[1]
        if b == "X":
            score += (a - 1) % 3 + 1
        if b == "Y":
            score += a + 4
        if b == "Z":
            score += (a + 1) % 3 + 7
    print(score)
