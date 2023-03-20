#include<stdio.h>

int main(){
    int size; //define variable size
    printf("please enter the size:\n");
    scanf("%d", &size);

    for(int i=size; i<=size && i>0; i--){
        for(int j=size; j>=i; j--){
            printf("*");
        } //end for
        printf("\n");
    } //end for

    return 0; //indicate program ended successfully
} //end function main