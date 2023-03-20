#include<stdio.h>
#include<stdlib.h>
#define n 20

int judge_numbers(int a[]);

int main(){
    int arr[n], i, j;
    while(1){
        printf("Enter %d numbers between 10 and 100:", n);
        for(i=0; i<n; i++){ //輸入陣列數字
            scanf("%d", &arr[i]);
        }
        if(judge_numbers(arr) == 1){
            break;
        }
    }
    printf("The non-duplicated elements are:");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(arr[i]==arr[j] && i!=j){
                break;
            }
        }
        if(j == n){
            printf("%2d", arr[i]);
            putchar(' ');
        }
    }
    printf("\n");
    return 0;
}

int judge_numbers(int a[]){
    for(int i=0; i<n; i++){
        if(a[i]<10 || a[i]>100){ //判斷陣列數字是否介於10~100
            printf("Your numbers are out of range. Please enter again.\n");
            return 0;
        }
    }
    return 1;
}

