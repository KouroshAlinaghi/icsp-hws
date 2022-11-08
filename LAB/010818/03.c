#include <stdio.h>

int g(int y) {
  int j = 2;
  y = j * 3;
  return y;
}

int f(int x) {
  return g(x);
}

int main() {
  int a = 1;
  printf("%d", f(a)); // f(1) = g(1) = j * 3 = 2 * 3 = 6
  return 0;
}
