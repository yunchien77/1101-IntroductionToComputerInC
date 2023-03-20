#include<stdio.h>
#include<assert.h>
//讓使用者自行輸入陣列大小及數值，之後將二維陣列做氣泡降排序法後輸出

int main(){
    int size, i, j, k, r, temp;
    printf("Enter the order of the matrix:"); //輸入二維陣列大小
    scanf("%d", &size);
    assert(size>=3 && size<=10);
    int arr[size][size]; 
    printf("Enter your entries for the input mat:\n"); //輸入二維陣列數值
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    //bubble sort of 2d array in descending order
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
    //using nested loops to output the 2d array
    for(i=0; i<size; i++){ 
        for(j=0; j<size; j++){
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}