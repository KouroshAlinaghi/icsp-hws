#include <stdio.h>

int main() {
  long int a;
  scanf("%ld", &a);
  six(a);
  return 0;
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
