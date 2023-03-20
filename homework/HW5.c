#include<stdio.h>
#include<math.h>
double Length(double num1, double num2)
{
    double i = sqrt(num1*num1 + num2*num2);
    return i;
}

int main(void)
{
    int x = 3, y = 4;
    printf("Before Normalize: (x, y) = (%d, %d)\n", x, y);
    printf("After Normalize: (x, y) = (%.1f, %.1f)\n", x/Length(x, y), y/Length(x, y));
    return 0;
}