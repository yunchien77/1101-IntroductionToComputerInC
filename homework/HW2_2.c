#include<stdio.h>
int main(){
    double f, c;
    printf("Please enter a temperature in Fahrenheit:");
    scanf("%lf", &f);

    c = 5.0/9.0 * (f - 32);

    printf("%3.0f Fahrenheit = %5.3f Celsius", f, c);
    return 0;
}