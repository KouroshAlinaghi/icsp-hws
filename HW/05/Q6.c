#include <stdlib.h>
#include <math.h>

#define ARRAY_LENGTH 5

float calc_mean(float* data_array) {
    int sum = 0;
    for (int i=0; i<ARRAY_LENGTH; i++)
        sum += data_array[i];

    return sum / ARRAY_LENGTH;
}

float calc_standard_deviation(float* data_array) {
    int avg = calc_mean(data_array), sum = 0;
    for (int i=0; i<ARRAY_LENGTH; i++) {
        sum += (data_array[i] - avg)*(data_array[i] - avg);
    }

    return sqrt(sum/ARRAY_LENGTH);
}

float calc_cv(float* data_array) {
    return calc_standard_deviation(data_array) / calc_mean(data_array);
}
