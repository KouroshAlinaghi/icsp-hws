#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// A better algorithm was to check (n % i == 0) for
// just prime numbers less than [sqrt(n)], but since
// that would require recursive function calls, I 
// avoided doing it in that way.
bool is_prime(int n) {
  if (n < 2) return false;

  int sqrt_floor = sqrt(n);
  int i = 2;

  while (i <= sqrt_floor) {
    if (n % i == 0) return false;
    i++;
  }

  return true;
}

int main() {
  int i = 1, n;
  printf("Please enter a natural number:\n");
  scanf("%d", &n);
  
  // We could add 2 to i in each loop (i += 2) and just check
  // that i is prime, but since the question used the 
  // term "odd number", I decieded to check if the number 
  // is odd as well.
  while (i <= n) {
    if (is_prime(i) && i % 2 == 1) printf("%d\n", i);
    i++; 
  }

  return 0;
}

