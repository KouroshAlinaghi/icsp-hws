#include <stdio.h>
#include <stdbool.h>

int GCD(int a, int b) {
  int c;

  while (b != 0) {
    c = a;
    a = b;
    b = c%b; // so basically it's going to be GCD(b, a%b)
  }

  return a; // returns when b == 0
}

bool are_relatively_prime(int a, int b) {
  return GCD(a, b) == 1;
}

int main() {
  int a, b;
  printf("Enter two numbers seperated by -\n");
  scanf("%d-%d", &a, &b);
  int a_last_digit = a % 10;
  int b_last_digit = b % 10;
  
  if (are_relatively_prime(a_last_digit, b_last_digit)) {
    printf("%d and %d are relatively prime!", a_last_digit, b_last_digit);
  } else {
    printf("%d and %d are not relatively prime.", a_last_digit, b_last_digit);
  }

  return 0;
}
