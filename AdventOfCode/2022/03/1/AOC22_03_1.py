import sys


def getCharPriority(c):
    if c.isupper():
        return ord(c) - ord("A") + 27
    else:
        return ord(c) - ord("a") + 1


if __name__ == "__main__":
    input_file = open(sys.argv[1])
    score = 0
    for line in input_file.readlines():
        l = len(line) // 2
        left = line[l:]
        right = line[:l]
        intersect = "".join(set(left).intersection(right))
        for c in intersect:
            score += getCharPriority(c)
    print(score)
