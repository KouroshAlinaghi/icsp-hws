#include <stdio.h>

int main() {
    int x, y;
    printf("Please enter two numbers, seperated by space:\n");
    scanf("%d %d", &x, &y);
    printf("Result: %d\n", ((x + y) << 2) % 3);

    return 0;
}
