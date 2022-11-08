#include <stdio.h>
#include <stdbool.h>

int multipy_table() {
    printf("Recieved 1, please enter two natural numbers seperated by -\n");
    int n, m;
    scanf("%d-%d", &n, &m);
    if (n < 1 || m < 1) {
        printf("I said natural numbers.\n");
        return 1;
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%d ", i*j);
            }
            printf("\n");
        }
        return 0;
    }
}

int triangle() {
    printf("Recieved 2, please enter a natural number bigger than 2\n");
    int m;
    scanf("%d", &m);
    if (m < 3) {
        printf("You are stupid.\n");
        return 1;
    } else {
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
}

int main() {
    while (true) {
        int option;
        printf("Please enter an option:\n0) Terminate Program\n1) Multipy Table\n2) Triangle\n");
        scanf("%d", &option);
        switch (option) {
            case 0:
                printf("Recieved 0, terminating program...\n");
                return 0;
            case 1:
                if (multipy_table() == 1) {
                    continue;
                } else {
                    return 0;
                }
            case 2:
                if (triangle() == 1) {
                    continue;
                } else {
                    return 0;
                }
            default: 
                printf("Unknown option\n");
                continue;
        }
    }
}
