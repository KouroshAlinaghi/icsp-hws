#include <stdio.h>

long fib(long n) {
  if (n <= 2)
    return 1;

  return fib(n-1) + fib(n-2);
}

int main() {
  printf("%ld", fib(5));

  return 0;
}
