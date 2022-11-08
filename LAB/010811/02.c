#include <stdio.h>

int main() {
    int n, m;
    printf("Enter two numbers, seperated by -\n");
    scanf("%d-%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%d ", i*j);
        }
        printf("\n");
    }
    return 0;
}