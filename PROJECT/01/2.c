#include <stdio.h>

// since we're not allowed to use arrays,
// here's a switch case for getting energy
// for a given food
int get_energy_for_food(int food_number) {
    switch (food_number) {
        case 0:
            return 329;
            break;
        case 1:
            return 127;
            break;
        case 2:
            return 61;
            break;
        case 3:
            return 83;
            break;
        case 4:
            return 156;
            break;
        case 5:
            return 296;
            break;
        case 6:
            return 496;
            break;
        case 7:
            return 73;
            break;
        case 8:
            return 34;
            break;
        case 9:
            return 16;
            break;
        default:
            return 0;
            break;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // energy gained
    int gain_sum = 0;
    for (int i=1; i<=n; i++) {
        int index;
        scanf("%d", &index);
        gain_sum += get_energy_for_food(index-1);
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
