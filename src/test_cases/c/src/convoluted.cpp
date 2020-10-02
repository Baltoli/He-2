#include <stdio.h>

int do_nothing();

int do_nothing() { return 5; }

int main()
{
  // this is a simple convoluted c file computing the square of a number - our
  // method should be resilient to this

  int a;
  int (*Nothing)(void) = do_nothing;
  goto label_1;
  Nothing();
label_2:
  a = a * a;
  goto label_3;

label_1:
  goto label_2;

label_3:
  return 0;
}

