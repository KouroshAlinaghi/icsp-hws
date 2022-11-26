#include <stdio.h>

int main() {
  char msg[5] = "Hello";

  int len;
  for (len=0; msg[len] != '\0'; len++);
  printf("%d\n", len);

  return 0;
}
