#include<stdio.h>
int main()
{
    int a, b, c, temp;
    printf("please enter the three lengths of triangle:\n");
    scanf("%d%d%d", &a, &b, &c);
    printf("Before sorting: %d %d %d\n", a, b, c);

    //compare a and b and c(由小到大排列)
    if (b < a){
        temp = a; a = b; b = temp;
    }
    if (c < a){
        temp = c; c = a; a = temp;
    }
    if (c < b){
        temp = c; c = b; b = temp;
    }
    printf("After sorting: %d %d %d\n", a, b, c);

    //判別三角形
    if (a + b > c){
        if(a == b && a == c){
            printf("It's a equilateral triangle!\n");
        }
        else if(a == b || b == c || a == c){
            printf("It's an isosceles triangle!\n");
        }
        else if(c*c == a*a + b*b){
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