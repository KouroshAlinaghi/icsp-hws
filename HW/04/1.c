#include <stdio.h>

int main() {
    int array[100], n, c, d, swap;

    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("Enter %d integers\n", n); // fix: &n -> n, we need to pass the value of n.

    c = 0;
    while (c < n) { // we need to give c a default value: 0
                     // another problem: (c <= n) is wrong, (c < n)
        scanf("%d", &array[c]); // we need to check if n <= 100
        c++;
    }

    for (c = 0; c < n - 1; c++) {
        for (d = 0; d < n - c - 1; d++) {
            if (array[d] > array[d+1]) {
                swap = array[d]; // this line should be before last line.
                array[d] = array[d+1];
                array[d+1] = swap;
            }
        }
    }

    printf("Sorted list in ascending order\n");

    for (c = 0; c < n; c++) // c <= n is wrong, c < n
        printf("%d\n", array[c]);

    return 0;
}