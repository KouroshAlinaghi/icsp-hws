int main() {
    int arr[4] = {1,2,3,4};
    /*
        Pointers are never copies, they are just
        "pointers", pointing to same values in memory.
        If the original values change, they'll change as well.
    */
    int *arr_cpy;
    arr_cpy = arr;

    // Real solution:
    int my_arr_copy[4];
    for (int i=0; i<4; i++)
        my_arr_copy[i] = arr[i];
        
    return 0;
}