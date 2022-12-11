void sort(int *a, int *b, int *c) {
    int temp;
    int helper_array[3] = {*a, *b, *c};
    for (int i=0; i<2; i++) {
        for (int j=0; j<i+2; j++) {
            if (helper_array[j] > helper_array[j+1]) {
                temp = helper_array[j];
                helper_array[j] = helper_array[j+1];
                helper_array[j+1] = temp;
            }
        }
    }

    *a = helper_array[0];
    *b = helper_array[1];
    *c = helper_array[2];
}
