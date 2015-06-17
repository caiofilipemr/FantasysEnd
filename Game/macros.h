#ifndef MACROS_H
#define MACROS_H

#define hasPoint(x, y) (x > xb && x < xe && y > yb && y < ye)

#define increase(a, b, c) a++; b++; c++;

#define LOOP_OPTION(s, n) if (s == n) s = 0;\
                          else if (s < 0) s = n - 1;

#endif // MACROS_H
