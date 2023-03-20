#include<stdio.h>
#define n 20
//判斷出重複數字的程式碼
int judge_numbers(int a[]);
int main(){
    int arr[n], arr2[n], k=0, r, flag, i, j;
   
    while(1){
        printf("Enter %d numbers between 10 and 100:", n);
        for(i=0; i<n; i++){ //輸入陣列數字
            scanf("%d", &arr[i]);
        }
        if(judge_numbers(arr) == 1){
            break;
        }
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            flag = 0;
            if(i != j && arr[i] == arr[j]){
                for(r=0; r<k; r++){
                    if(arr2[r] == arr[j]){
                        flag = 1;
                    }
                }
                if(flag != 1){
                    arr2[k++] = arr[j];
                }
            }
        }
    }
    printf("The duplicated numbers are:");
    for(i=0; i<k; i++){
        printf("%d", arr2[i]);
        putchar(' ');
    }
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
