import sys

if __name__ == "__main__":
    input_file = open(sys.argv[1])
    score = 0
    for line in input_file.readlines():
        line = line.strip().split(" ")
        input_file = open(sys.argv[1])
        a = ord(line[0]) - ord("A")
        b = ord(line[1]) - ord("X")
        score += b + 1
        if b == (a + 1) % 3:
            score += 6
        elif b == a:
            score += 3
    print(score)
