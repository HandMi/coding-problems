import sys
import itertools

def getCharPriority(c):
    if c.isupper():
        return ord(c) - ord("A") + 27
    else:
        return ord(c) - ord("a") + 1


if __name__ == "__main__":
    input_file = open(sys.argv[1])
    score = 0

    with open(sys.argv[1]) as f:
        for line1,line2,line3 in itertools.zip_longest(*[f]*3):
            intersect1 = "".join(set(line1).intersection(line2))
            intersect2 = "".join(set(intersect1).intersection(line3))
            for c in intersect2.strip():
                score += getCharPriority(c)
    print(score)
