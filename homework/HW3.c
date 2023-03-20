#include<stdio.h>
int main()
{
    int a, b, i;
    printf("please enter the first integer:\n");
    scanf("%d", &a);
    printf("please enter the second integer:\n");
    scanf("%d", &b);
    a = a + b;

    for(i=1; i<=100; i++){
        printf("enter the next integer:\n");
        scanf("%d", &b);
        a = a + b;
    }
    printf("%d\n", a);

    return 0;
}