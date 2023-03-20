#include<stdio.h>
int main()
{
    int integer1, integer2;
    printf("please enter the first integer:\n");
    scanf("%d", &integer1);
    printf("please enter the second integer:\n");
    scanf("%d", &integer2);

    int a = integer1 + integer2;
    printf("first integer plus second one = %d\n", a);
    a = integer1 - integer2;
    printf("subtract second one from first one = %d\n", a);
    a = integer1 * integer2;
    printf("first integer multiply second one = %d\n", a);
    a = integer1 / integer2;
    printf("first integer divided second one = %d\n", a);
    a = integer1 % integer2;
    printf("the remainder when first one divided second one = %d\n", a);

    return 0;
}
