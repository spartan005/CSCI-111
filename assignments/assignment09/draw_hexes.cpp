// Section 07 Gamma, James Oppy
#include"hexagon.h"

void hex(int times, int go)
{
  for (int a = times; a < 10; ++a) { 
    moveForward();
    turnRightBy(60 * go);
  }
}

int main()
{
  int go = 1;
  bool even = false;
  for (int b = 13; b > 0; --b) 
  {
    for (int i = 11; i > -11; --i)
    {
      if (i == 0) { 
        go = -1;
      }
      hex (0, go);
      turnRightBy(120 * go);
    }
    go = 1;
    if (even == false && b > 1) {
      even = true;
      hex (9, 5);
      hex (9, 1);
    }
    else if (even == true && b > 1) {
      even = false;
      hex (9, 1);
      hex (9, 5);
    }
  }

  return 0;
}
