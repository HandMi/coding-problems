#ifndef CHECK_REMAINDER_H
#define CHECK_REMAINDER_H

bool CheckRemainder(int a, int b, int denomination, int sum) {
  if ((sum % denomination <= b) && (a * denomination + b >= sum)) {
    return true;
  } else {
    return false;
  }
}

#endif