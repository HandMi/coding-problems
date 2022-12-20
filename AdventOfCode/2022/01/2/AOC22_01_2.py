import sys

if __name__ == "__main__":
    input_file = open(sys.argv[1])
    cur = 0
    sums = []
    for line in input_file.readlines():
        if line.strip():
            cur += int(line)
        else:
            sums.append(cur)
            cur = 0
    sums.sort(reverse=True)
    print(sum(sums[:3]))
