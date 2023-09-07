#include <stdio.h>

long fib(long n) {
  if (n <= 0)
    return 0;
        
  int n1 = 0, n2 = 1;

  for (int i=1; i<n; i++)  {
    int sum = n1 + n2;
    n1 = n2;
    n2 = sum;
  }

  return n2;
}

int main() {
  int n;
  printf("Please enter a number\n");
  scanf("%d", &n);

  printf("%ld", fib(n));
}
