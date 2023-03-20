#include<stdio.h>
int main()
{
    int integer1, integer2;
    printf("please enter the first integer:\n");
    scanf("%d", &integer1);
    printf("please enter the second integer:\n");
    scanf("%d", &integer2);

    int sum, dif, pro, quo, rem;
    sum = integer1 + integer2;
    dif = integer1 - integer2;
    pro = integer1 * integer2;
    quo = integer1 / integer2;
    rem = integer1 % integer2;

    printf("first integer plus second one = %d\n", sum);
    printf("subtract second one from first one = %d\n", dif);
    printf("first integer multiply second one = %d\n", pro);
    printf("first integer divided second one = %d\n", quo);
    printf("the remainder when first one divided second one = %d\n", rem);

    return 0;
}
