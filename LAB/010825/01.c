#include <stdio.h>

int main() {
  int a = 5;
  int arr_a[a]; // hehe it doesn't throw any errors, cry about it.
              // "Variable Length Arrays have been part of C language since C99."
              // https://stackoverflow.com/questions/1677157/can-size-of-array-be-determined-at-run-time-in-c
  
  const int b = 5;
  int arr_b[b]; // it doesn't throw any errors as well.

  for (int i=0; i<5; i++) {
    scanf("%d", &arr_b[i]);
  }

  for (int i=4; i>=0; i--) {
    printf("%d\n", arr_b[i]);
  }

  return 0;

}
