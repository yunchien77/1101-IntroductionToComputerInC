#include<stdio.h>
int main(){
    int integer1, integer2;
    int sum1, sum2, sum3, sum4, sum5;

    printf("enter the first integer:\n");
    scanf("%d", &integer1);
    printf("enter the second integer:\n");
    scanf("%d", &integer2);
    
    sum1 = integer1 + integer2;
    sum2 = integer1 - integer2;
    sum3 = integer1 * integer2;
    sum4 = integer1 / integer2;
    sum4 = integer1 % integer2;

    printf("first integer plus second one = %d\n", sum1);
    printf("subtract second one from first one = %d\n", sum2);
    printf("first integer multiply second one = %d\n", sum3);
    printf("first integer divided second one = %d\n", sum4);
    printf("the remainder when first one divided second one = %d\n", sum5);

    return 0;
}