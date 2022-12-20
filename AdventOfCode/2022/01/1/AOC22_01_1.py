import sys

if __name__ == "__main__":
    input_file = open(sys.argv[1])
    max_sum = 0
    sum = 0
    for line in input_file.readlines():
        if line.strip():
            sum += int(line)
        else:
            max_sum = max(sum, max_sum)
            sum = 0
    print(max_sum)
