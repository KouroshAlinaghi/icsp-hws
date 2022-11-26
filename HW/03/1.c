#include <stdio.h>
#include <math.h>

int one(double a, double b, double c);

int main() {
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  one(a, b, c);
  return 0;
}

int one(double a, double b, double c) {
  double delta = b*b - 4*a*c;
  if (delta < 0) {
    printf("NO ROOT FOUND");
    return 1;
  }

  double x1 = (-b+(sqrt(delta)))/(2*a);
  if (delta > 0) {
    double x2 = (-b-(sqrt(delta)))/(2*a);
    if (x1 > x2) {
      printf("%.6f , ", x2);
      printf("%.6f", x1);
    } else {
      printf("%.6f , ", x1);
      printf("%.6f", x2);
    }
  } else {
    printf("%.6f ", x1);
    printf("NO ROOT FOUND");
  }

  return 0;
}
