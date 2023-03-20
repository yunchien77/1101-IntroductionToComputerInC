#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#define n 10
//這是一個將二維轉成一維陣列，再用選擇排序法做降排序，之後再轉成二維陣列輸出的麻煩過程
int selection_sort(int a[], int num);
int main(){
   int arr[n][n], size, i, j, k=0, w=0;
   printf("Enter the order of the matrix:"); //input the arraysize of 2d array
   scanf("%d", &size);
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
   int arr2[size*size]; //declare a 1D array
   //2D array convert to 1D array
   for(i=0; i<size; i++){ 
      for(j=0; j<size; j++){
         arr2[k] = arr[i][j];
         k++;
      }
   }
   //selection sort of 1D array
   selection_sort(arr2, size*size);
   
   //1D array convert to 2D array
   for(i=0; i<size; i++){ 
      for(j=0; j<size; j++){
         arr[i][j]=arr2[w];
         w++;
      }
   }
   //print 2D array
   printf("After sorting:\n");
   for(i=0; i<size; i++){ 
      for(j=0; j<size; j++){
         printf("%5d", arr[i][j]);
      }
      printf("\n");
   }
   return 0;
}

int selection_sort(int a[], int num){
    int temp;
    for(int i=0; i<num-1; i++){
        int min_idx = i;
        for(int j=i+1; j<num; j++){
            if(a[j] > a[min_idx]){
                min_idx = j;
            }
        }
        temp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = temp;
   }
   return 0;
}