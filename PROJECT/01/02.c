#include <stdio.h>

int main() {
    int energy_food[10] = {
        329,
        127,
        61,
        83,
        156,
        296,
        496,
        73,
        34,
        16
    };

    int n;
    // printf("Please enter the number of days:\n");
    scanf("%d", &n);

    // printf("Now pelase enter the number for each food you've eaten in last n days:\n");

    int gain_sum = 0;
    for (int i=1; i<=n; i++) {
        int index;
        scanf("%d", &index);
        gain_sum += energy_food[index-1];
    }

    if (gain_sum > n*100) {
        printf("chagh");
    } else if (gain_sum < n*100) {
        printf("laghar");
    } else {
        printf("bedoon taghir");
    }

    return 0;
}