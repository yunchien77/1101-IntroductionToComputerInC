#include<stdio.h>
#include<stdbool.h>
#define ArraySize 20
int judge_numbers(int a[]);
int main(){
    int array[ArraySize], i, j;
    while(1){
        printf("Enter %d numbers between 10 and 100:", ArraySize);
        for(i=0; i<ArraySize; i++){ //輸入陣列數字
            scanf("%d", &array[i]);
        }
        if(judge_numbers(array) == 1){
            break;
        }
    }

    printf("The non-duplicated numbers are:");
    for(i=0; i<ArraySize; i++){
        bool isRepeat = false;
        for(j=0; j<ArraySize; j++){
            if(i == j){ //當i == j，跳過
                continue;
            }
            else if(array[i] == array[j]){ //當陣列中索引值i的數等於陣列中索引值為J的數，則代表有數字重複
                isRepeat = true;
                break;
            }
        }
        if(!isRepeat){  //isRepeat = false
            printf("%d", array[i]);
            putchar(' ');
        }
    }
    return 0;
}
int judge_numbers(int a[]){
    for(int i=0; i<ArraySize; i++){
        if(a[i] < 10 || a[i] > 100){ //判斷陣列數字是否介於10~100
            printf("Your numbers are out of range. Please enter again.\n");
            return 0;
        }
    }
    return 1;
}