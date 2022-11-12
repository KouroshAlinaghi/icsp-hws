#include <math.h>
#include <stdio.h>

// JUST FOR CLARITY ON THE CONTENTS OF THIS FILE:

int one(float a, float b, float c);

int two(int a, int b);  
  // a helper function that takes an integer as a number and 
  // anothe integer as an index (zero-based, from right to left)
  // and returns the index'th digit of number.
  int get_digit(int number, int index);
  // another helper function for Q#2 that takes an integer 
  // and returns number of digits of the given number.
  int get_number_of_digits(int number);
  // yet another helper method since I wasn't sure if 
  // we are allowed to use pow() function from math.h
  int my_power(int base, int pow);

int three(int a);

int four(int number);

int five(int n);
  // defining a fib() function since we just want to
  // print and not to return result from five()
  int fib(int n);

int six(int days);

int one(float a, float b, float c) {
  float delta = b*b - 4*a*c;
  if (delta < 0) {
    printf("NO ROOT FOUND");
    return 1;
  }

  printf("%f\n", (-b+(sqrt(delta)))/(2*a));
  if (delta > 0)
    printf("%f\n", (-b-(sqrt(delta)))/(2*a));

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

int three(int hours) {
  hours = hours % (24*7); // since two even days are after each other (Friday, Saturday)
  int hour_in_day = hours % 24;

  // hours = 24 * m + hour_in_day

  // this is m in the above format.
  if ((hours - hour_in_day)/24 % 2 == 0) {
    if (hour_in_day < 12)
      printf("A\n");
    else
      printf("B\n");
  } else {
    if (hour_in_day < 12)
      printf("C\n");
    else
      printf("D\n");
  }

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

int five(int n) {
  printf("%ld\n", fib(n-1));
  return 0;
}

int fib(int n) {
  if (n <= 2)
    return 1;

  return fib(n-1) + fib(n-2);
}

int six(int days) {
  int years_passed = days/365;

  // we'll now focus on a "days" variable which is 
  // between 0 and 364
  days = days % 365;
  int month;
  for (month=1; month<=12; month++) {
    int days_in_current_month;
    if (month <= 6)
      days_in_current_month = 31;
    else if (month < 12) 
      days_in_current_month = 30;
    else
      days_in_current_month = 29;

    days -= days_in_current_month;
    if (days < 0) {
      printf("%d.%d.%d\n", 1300+years_passed, month, days+days_in_current_month+1);
      return 0;
    }
  }
}

//
// number[i] = (number % 10^(i+1) - number[i-1]) / 10^(i)
// NOTE: i is starting from zero and is rtl.
//
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
