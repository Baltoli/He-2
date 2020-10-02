#include <stdio.h>

int main()
{
  // basic arithmetic expressions
  int a0;
  int a1;

  // simple statements
  int plus = a0 + a1;
  int minus = a0 - a1;
  int mul = a0 * a1;
  int div = a0 / a1;
  int mod = a0 % a1;
  int and_ = a0 & a1;
  int or_ = a0 | a1;
  int xor_ = a0 ^ a1;
  int not_ = ~a0;

  // compound statements
  int comp_1 = (plus + minus) / (div * mod);
  int comp_2 = (xor_ - or_) / (and_ / not_);

  return 0;
}
