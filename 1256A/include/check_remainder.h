#ifndef CHECK_REMAINDER_H
#define CHECK_REMAINDER_H

bool CheckRemainder(int a, int b, int dividend, int sum) {
  if ((sum % dividend <= b) &&
      (static_cast<long long int>(dividend) * a + b >= sum)) {
    return true;
  } else {
    return false;
  }
}

#endif