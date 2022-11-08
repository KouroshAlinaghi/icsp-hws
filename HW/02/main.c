#include <stdio.h>

int main() {
  int a = 1, b = 1;
  for (int i = 11; b; a += 1) {
    b = 0;
    for (int j = 0; j < i; j++) {
      b += j - a;
    }
  }

  printf("%d", a);
  return 0;
}
