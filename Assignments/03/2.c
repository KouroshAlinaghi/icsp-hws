#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  two(a, b);
  return 0;
}

int two(int a, int b) {
  int a_digits = get_number_of_digits(a);
  if (get_number_of_digits(b) != a_digits) {
    printf("NO\n");
    return 1;
  }

  for (int i=0; i<a_digits; i++) {
    if (get_digit(a, i) != get_digit(b, a_digits-(i+1))) {
      printf("NO\n");
      return 1;
    }
  }

  printf("YES\n");
  return 0;
}

int get_digit(int number, int index) {
  if (index == 0)
    return number % 10;

  return (int)(number % my_power(10, index+1) - get_digit(number, index-1)) / my_power(10, index);
}

int get_number_of_digits(int number) {
  int step = 1;
  
  while (1) {
    if (number > my_power(10, step)) {
      step++;
    } else {
      return step;
    }
  }
}

int my_power(int base, int pow) {
  int result = 1;

  for (int i=1; i<=pow; i++) {
    result *= base;
  }

  return result;
}
