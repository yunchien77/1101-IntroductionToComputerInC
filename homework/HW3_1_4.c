#include<stdio.h>
#include<math.h>
int main()
{
    int a, b, c, temp;
    printf("please enter the three lengths of triangle:\n");
    scanf("%d%d%d", &a, &b, &c);
    printf("Before sorting: %d %d %d\n", a, b, c);

    //compare a and b and c(由大到小排列)
    if (a < b){
        temp = a; a = b; b = temp;
    }
    if (a < c){
        temp = c; c = a; a = temp;
    }
    if (b < c){
        temp = c; c = b; b = temp;
    }
    printf("After sorting: %d %d %d\n", a, b, c);

    //使用pow進行指數運算
    int d = pow(a, 2);
    int e = pow(b, 2);
    int f = pow(c, 2);

    //判別三角形
    if (b + c > a){
        if(a == b && a == c){
            printf("It's a equilateral triangle!\n");
        }
        else if(a == b || b == c || a == c){
            printf("It's an isosceles triangle!\n");
        }
        else if(d == e + f){
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