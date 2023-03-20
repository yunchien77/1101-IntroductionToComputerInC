#include<stdio.h>
#include<assert.h>
#include<time.h>
#include<stdlib.h>
#define n 10
//讓使用者輸入陣列大小，由系統產生數值亂數，之後將二維陣列做氣泡降排序法後輸出

int main(){
    int arr[n][n], size, i, j, k, temp;
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
    for(k=0; k<size*size; k++){  //size*size is same as ROW*COL
        for(i=0; i<size; i++){  //size is same as ROW
            for(j=0; j<size-1; j++){  //size is same as COL
                if(arr[i][j]<arr[i][j+1]){
                    temp = arr[i][j+1];
                    arr[i][j+1] = arr[i][j];
                    arr[i][j] = temp;
                }
            }
        }
        for(i=0; i<size-1; i++){  //size is same as ROW
            if(arr[i][size-1]<arr[i+1][0]){  //size is same as COL
                temp = arr[i+1][0];
                arr[i+1][0] = arr[i][size-1];  //size is same as COL
                arr[i][size-1] = temp;  //size is same as COL
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