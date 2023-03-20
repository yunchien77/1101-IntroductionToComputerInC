#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void bubble_sort(int *arr, int*);
int main(){
    int size;
    printf("Please enter the matrix of the array:\n");
    scanf("%d", &size);
    int arr[size];
    srand(time(NULL));
    for(int i=0; i<size; i++){
        arr[i] = rand() % 100 + 1; //產生一個元素介於1~100的陣列
    }
    printf("Before descending order: ");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    //將陣列數字由大到小排序後印出(bubble sort)
    bubble_sort(arr, &size);
    
    printf("\nAfter descending order: ");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
void bubble_sort(int *arr, int *size){
    int temp;
    for(int i=0; i<*size-1; i++){
        for(int j=0; j<*size-1-i; j++){
            if(arr[j] < arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}