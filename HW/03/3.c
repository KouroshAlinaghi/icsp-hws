#include <stdio.h>

int main() {
  int a;
  scanf("%d", &a);
  three(a);
  return 0;
}

int three(int hours) {
  hours = hours % (24*7); // since two even days are after each other (Friday, Saturday)
  int hour_in_day = hours % 24;

  // hours = 24 * m + hour_in_day

  // this is m in the above format.
  if ((hours - hour_in_day)/24 % 2 == 0) {
    if (hour_in_day < 12)
      printf("A");
    else
      printf("B");
  } else {
    if (hour_in_day < 12)
      printf("C");
    else
      printf("D");
  }

  return 0;
}
