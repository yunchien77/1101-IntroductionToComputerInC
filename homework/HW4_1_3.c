#include<stdio.h>

int main(){
    int size; //define variable size
    printf("please enter the size:\n");
    scanf("%d", &size);

    for(int i=1; i<=size; i++){
        for(int j=size; j>=i; j--){
            printf("*");
        } //end for
        printf("\n");
    } //end for

    return 0; //indicate program ended successfully
} //end function main