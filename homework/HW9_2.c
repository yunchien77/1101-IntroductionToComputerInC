#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void bubble_sort(int *, int *);
int main(){
    int size;
    printf("please enter the matrix of the array:\n");
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
    
    bubble_sort(arr, &size);
    printf("\nAfter descending order: ");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
void bubble_sort(int *ptr, int *size){
    int temp;
    for(int i=0; i<*size-1; i++){
        for(int j=0; j<*size-1-i; j++){
            if(*(ptr+j) < *(ptr+j+1)){
                temp = *(ptr+j+1);
                *(ptr+j+1) = *(ptr+j);
                *(ptr+j) = temp;
            }
        }
    }
}