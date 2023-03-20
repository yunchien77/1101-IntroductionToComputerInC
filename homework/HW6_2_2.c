#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#define n 10
//這是一個將二維轉成一維陣列，再用氣泡排序法由大到小做排序，之後再轉成二維陣列輸出的麻煩過程
int bubble_sort(int a[], int num);
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
   //bubble sort of 1D array
   bubble_sort(arr2, size*size);

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

int bubble_sort(int a[], int num){
    int temp;
    for(int i=0; i<num-1; ++i){ 
        for(int j=0; j<num-1-i; ++j){
            if(a[j]<a[j+1]){
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
   return 0;
}