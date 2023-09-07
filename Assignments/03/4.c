#include <stdio.h>
#include <math.h>

int main() {
  int a;
  scanf("%d", &a);
  four(a);
  return 0;
}

int four(int number) {
  int flag = 0;

  for (int i=2; i<=number; i++) {
    flag = 0;

    for (int j=2; j<=sqrt(i); j++) {
      if (i % j == 0) {
        flag = 1;
        break;
      }
    }
  
    if (flag == 0)
      printf("%d ", i);

  }

  return 0;
}
