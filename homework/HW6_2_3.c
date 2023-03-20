#include<stdio.h>
#include<assert.h>
#include<time.h>
#include<stdlib.h>
#define n 10
//讓使用者輸入陣列大小，由系統產生數值亂數，之後將二維陣列做氣泡降排序法後輸出

int main(){
    int arr[n][n], size, i, j, k, r, temp;
    //input the array size of the 2D array
    printf("Enter the order of the matrix:"); 
    scanf("%d", &size);
    //if the array size is smaller than 3 or larger than 10, main function will stop
    assert(size>=3 && size<=10);
    //generate random values of the 2D array in the range of 10 to 100
    srand(time(NULL));
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            arr[i][j] = rand()%91 + 10;
        }
    }
    //output the random values before sorting
    printf("Before sorting:\n");
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    //bubble sort in descending order
    for(i=0; i<size; i++){ 
        for(j=0; j<size; j++){
            temp = arr[i][j];
            r = j+1;
            for(k=i; k<size; k++){
                while(r<size){
                    if(temp<arr[k][r]){
                        temp = arr[k][r];
                        arr[k][r] = arr[i][j];
                        arr[i][j] = temp;
                    }
                    r++;
                }
                r=0;
            }
        }
    }
    //output the random values after sorting
    printf("After sorting:\n");
    for(i=0; i<size; i++){ 
        for(j=0; j<size; j++){
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}