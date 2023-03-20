#include<stdio.h>
int main()
{
    double a, b, c, temp;
    printf("please enter the three lengths of triangle:\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("Before sorting: %4.2f %4.2f %4.2f\n", a, b, c);

    //compare a and b and c
    if (a < b){
        temp = a; a = b; b = temp;
    }
    if (a < c){
        temp = c; c = a; a = temp;
    }
    if (b < c){
        temp = c; c = b; b = temp;
    }
    printf("After sorting: %4.2f %4.2f %4.2f\n", a, b, c);

    //判別三角形
    if (b + c > a){
        if(a == b && a == c){
            printf("It's a equilateral triangle!\n");
        }
        else if(a == b || b == c || a == c){
            printf("It's an isosceles triangle!\n");
        }
        else if(a*a == b*b + c*c){
            printf("It's a right triangle!\n");
        }
        else{
            printf("It's just an ordinary triangle!\n");
        }
    }
    else{
        printf("It's not a triangle!\n");
    }
    
    return 0;
}