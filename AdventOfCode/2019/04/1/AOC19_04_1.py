def is_6_digit(x):
    return x[0] > 0 and len(x) == 6


def has_same_digits(x):
    result = False
    for i in range(0, len(x)-1):
        result = result or (x[i] == x[i+1])
    return result


def is_increasing(x):
    result = True
    for i in range(0, len(x)-1):
        result = result and (x[i] <= x[i+1])
    return result


if __name__ == '__main__':
    count = 0
    for i in range(158126, 624574):
        x = [int(j) for j in str(i)]
        count += is_6_digit(x) and has_same_digits(x) and is_increasing(x)
    print(count)
