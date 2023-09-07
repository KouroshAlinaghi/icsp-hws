#include <stdio.h>
#include <ctype.h>

int main() {
  char arr[5][21];

  for (int i=0; i<5; i++) {
    scanf("%s", arr[i]);
  }

  for (int i=1; i<5; i++) {
    for (int j=0; arr[i][j] != '\0'; j++) {
      for (int m=0; arr[0][m] != '\0'; m++) {
        if (tolower(arr[0][m]) == tolower(arr[i][j]))
          arr[i][j] = '$';
      }
    }
  }

  for (int i=0; i<5; i++) {
    for (int j=0; arr[i][j] != '\0'; j++) {
      printf("%c", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
