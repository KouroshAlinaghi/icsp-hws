int main() {
  int arr[4] = {1, 2, 3, 4};
  int arr_copy[4];

  // arr_copy = arr;
  // compiler doesn't allow us to do that.
  // one reason is that it will not copy the values
  // to arr_copy. but I don't see why it should raise
  // compile-time error, since p1 = p2 is already allowed.
  // TODO: ask why.

  for (int i=0; i<4; i++) 
    arr_copy[i] = arr[i];

  return 0;
}
