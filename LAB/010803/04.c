#include <stdio.h>
#define PI 3.1416

int main() {
    double r, result;
    printf("Please enter radius:\n");
    scanf("%lf", &r);
    result = PI * r * r;
    printf("Result is %.3f\n", result);

    return 0;
}
