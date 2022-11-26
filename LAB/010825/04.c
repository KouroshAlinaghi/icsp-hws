#include <stdio.h>

int main() {
  int arr[10] = {3, 2, 5, 4, 1, 2, 3, 8, 3, 6};

  float avg, sum = 0;
  for (int i=0; i<10; i++)
    sum += arr[i];

  avg = sum/10;

  int ans[10];

  for (int i=0; i<10; i++) {
    int max_index = 0;
    int flag = 0;

    for (int j=i; j>=0; j--) {
      if (arr[j] > arr[i]) {
        max_index = j;
        flag = 1;
        break;
      }
    }
    
    if (flag) {
      ans[i] = max_index;
    } else {
      ans[i] = -1;
    }
  }

  for (int i=0; i<10; i++)
    printf("%d\n", ans[i]);
}
