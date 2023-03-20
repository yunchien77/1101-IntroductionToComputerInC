#include<stdio.h>
int main(void)
{
    int size;
    printf("please enter the size:\n");
    scanf("%d", &size);

    for(int i=0; i<size; i++){
        for(int j=size; j>i; j--){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}