#include <stdio.h>
#define n 20
int judge_numbers(int a[]);
int main (){
    int arr[n], i, j, k, size=20;
    while(1){
        printf("Enter %d numbers between 10 and 100:", size);
        for(i=0; i<size; i++){ //輸入陣列數字
            scanf("%d", &arr[i]);
        }
        if(judge_numbers(arr) == 1){
            break;
        }
    }
    // use nested for loop to find the duplicate elements in array
    for(i=0; i<size; i++){
        for(j=i+1; j<size; j++){
            if(arr[i] == arr[j]){
                // delete the current position of the duplicate element
                for(k=j; k<size-1; k++){
                    arr[k] = arr[k+1];
                }
                // decrease the size of array after removing duplicate element
                size--;
                // if the position of the elements is changes, don't increase the index j
                j--;
            }
        }
    }
    printf("The non-duplicated numbers are:");
    for(i=0; i<size; i++){
        printf ("%3d", arr[i]);
    }
    return 0;
}

int judge_numbers(int a[]){
    for(int i=0; i<n; i++){
        if(a[i] < 10 || a[i] > 100){ //判斷陣列數字是否介於10~100
            printf("Your numbers are out of range. Please enter again.\n");
            return 0;
        }
    }
    return 1;
}