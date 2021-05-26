def is_6_digit(x):
    return x[0] > 0 and len(x) == 6


def has_double_digits(x):
    result = False
    match = False
    last_match = False
    for i in range(0, len(x)-1):
        new_match = x[i] == x[i+1]
        result = result or (
            not last_match and match and not new_match)
        last_match = match
        match = new_match

    result = result or (not last_match and match)
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
        if is_6_digit(x) and has_double_digits(x) and is_increasing(x):
            count += 1
    print(count)
