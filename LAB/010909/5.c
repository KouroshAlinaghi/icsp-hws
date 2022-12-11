#include <stdio.h>
#include <string.h>

int compare(char* first_array, char* second_array);

int main() {
    char first_array[70], second_array[70];
    scanf("%s", first_array);
    scanf("%s", second_array);
    printf("%d\n", compare(first_array, second_array));
    printf("first_array: %s\n", first_array);
    printf("second_array: %s\n", second_array);
}

int compare(char* first_array, char* second_array) {
    if (strcmp(first_array, second_array) == 0) {
        return strlen(first_array);
    } else {
        strcpy(second_array, first_array);
    }

    return 0;
}