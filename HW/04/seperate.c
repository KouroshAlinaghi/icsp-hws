#include <stdio.h>

void seperate(int arr[], int sizeArr) {
    // we calculate the number of even numbers and odd numbers
    // in arr[] so we can use them to create our odds[] and evens[]
    // array with known size.
    int num_of_odds = 0, num_of_evens = 0;

    for (int i=0; i<sizeArr; i++) {
        if (arr[i] % 2 == 0) {
            num_of_evens++;
        } else {
            num_of_odds++;
        }
    }

    int odds[num_of_odds], evens[num_of_evens];

    // Sorting array
    for (int i=0; i<sizeArr; i++) {
        for (int j=0; j<sizeArr-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Pushing each number to it's proper array (odd/even)
    num_of_evens = 0;
    num_of_odds = 0;
    for (int i=0; i<sizeArr; i++) {
        if (arr[i] % 2 == 0) {
            evens[num_of_evens] = arr[i];
            num_of_evens++;
        } else {
            odds[num_of_odds] = arr[i];
            num_of_odds++;
        }
    }

    // Printing Odds:
    for (int i=0; i<num_of_odds; i++) {
        if (i == num_of_odds-1) {
            printf("%d\n", odds[i]);
            break;
        }

        printf("%d,", odds[i]);
    }

    // Printing Evens:
    for (int i=0; i<num_of_evens; i++) {
        if (i == num_of_evens-1) {
            printf("%d\n", evens[i]);
            break;
        }
        printf("%d,", evens[i]);
    }
}