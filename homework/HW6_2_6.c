#include<stdio.h>
#include<assert.h>
#include<time.h>
#include<stdlib.h>
#define n 10
//讓使用者輸入陣列大小，由系統產生數值亂數，之後將二維陣列做選擇降排序法後輸出

int main(){
    int arr[n][n], size, i, j;
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
    //selection sort in descending order
    int rMAX, cMAX, MAX;
    for(int rOUT=0; rOUT<size; rOUT++){
        for(int cOUT=0; cOUT<size; cOUT++){
            rMAX = rOUT;
            cMAX = cOUT;
            MAX = arr[rOUT][cOUT];
            for(int cIN=cOUT+1; cIN<size; cIN++){
                if(arr[rOUT][cIN] > MAX){
                    rMAX = rOUT;
                    cMAX = cIN;
                    MAX = arr[rOUT][cIN];
                }
            }
            for(int rIN = rOUT+1; rIN<size; rIN++){
                for(int cIN = 0; cIN<size; cIN++){
                    if(arr[rIN][cIN] > MAX){
                        rMAX = rIN;
                        cMAX = cIN;
                        MAX = arr[rIN][cIN];
                    }
                }
            }
            arr[rMAX][cMAX] = arr[rOUT][cOUT];
            arr[rOUT][cOUT] = MAX;
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