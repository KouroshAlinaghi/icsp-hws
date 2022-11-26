#include <stdio.h>

void five(int n);
int fib(int n);

int main() {
  int a;
  scanf("%d", &a);
  five(a);
  return 0;
}

void five(int n) {
  if (n <= 0)
    return 0;
        
  int n1 = 0, n2 = 1;

  for (int i=1; i<n; i++)  {
    int sum = n1 + n2;
    n1 = n2;
    n2 = sum % (int)(1e9+7);
  }

  printf("%d", n2);

}

int fib(int n) {

}
