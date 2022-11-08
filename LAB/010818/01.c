#include <stdio.h>
#include <math.h>
#include "fact.h"

int main() {
  int x, n, sum = 0;
  printf("Please enter a number\n");
  scanf("%d", &n);

  for (int i=0; i<=n; i++) {
    sum += fact(i) * pow(-1, i);
  }

  printf("%d", sum);

  return 0;
}
