#include <stdio.h>

int main() {
    int m;
    printf("Enter a number\n");
    scanf("%d", &m);
    int lines = (m+1)/2;
    for (int i = 1; i <= lines; i++) {
        for (int j = 1; j <= m; j++) {
            if (j > lines-i && j < lines+i) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}