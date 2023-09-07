#include <stdio.h>

int compare(char* first_array, char* second_array);

int main() {
    char first_array[70], second_array[70];
    scanf("%s", first_array);
    scanf("%s", second_array);
    printf("%d\n", compare(first_array, second_array));
}

int compare(char* first_array, char* second_array) {
    for (int i=0; (first_array[i] != '\0' && second_array[i] != '\0'); i++) {
        if (first_array[i] != second_array[i])
            return 0;
    }

    return 1;
}