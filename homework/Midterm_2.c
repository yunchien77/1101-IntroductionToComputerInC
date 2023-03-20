#include<stdio.h>
#include<assert.h>

int binary_search(int, int, int, int arr[]);
int main(){
    int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28};
    int size = sizeof(arr) / sizeof(int);
    int key, i;
    printf("Enter a number between 0 and 28: ");
    scanf("%d", &key);
    assert(key >= 0 && key <=28);
    
    printf("\nSubscripts:\n");
    //print the index of each element
    for(i=0; i<size; i++){
        printf("%2d", i);
        printf("%*s", 3, " ");
    }
    printf("\n-------------------------------------------------------------------------\n");

    int result = binary_search(0, size-1, key, arr);

    //ternary operator
    (result == -1)
        ? printf("%d not found", key)  //if result == -1 is true
        : printf("%d found in array element %d", key, result);  //if result == -1 is false

    return 0;
}

int binary_search(int left, int right, int key, int a[]){
    int i, middle = left + (right-left) / 2;
    if(left <= right){
        if(key == a[middle]){
            for(i=1; i<=left; i++){  //vertical alignment of the elements
                printf("%*s", 5, " ");
            }
            for(i=left; i<=right; i++){
                if(i == middle){
                    printf("%2d%c", a[i], '*');  //label the middle index of the subarray
                    printf("%*s", 2, " ");
                }
                else{
                    printf("%2d", a[i]);
                    printf("%*s", 3," ");                    
                }
            }
            printf("\n");
            return middle;
        }
        else if(key < a[middle]){
            for(i=1; i<=left; i++){  //vertical alignment of the elements
                printf("%*s", 5, " ");
            }
            for(i=left; i<=right; i++){
                if(i == middle){
                    printf("%2d%c", a[i], '*');  //label the middle index of the subarray
                    printf("%*s", 2, " ");
                }
                else{
                    printf("%2d", a[i]);
                    printf("%*s", 3," ");                    
                }
            }
            printf("\n");
            return binary_search(left, middle-1, key, a);
        }
        else{
            for(i=1; i<=left; i++){  //vertical alignment of the elements
                printf("%*s", 5, " ");
            }
            for(i=left; i<=right; i++){
                if(i == middle){
                    printf("%2d%c", a[i], '*');  //label the middle index of the subarray
                    printf("%*s", 2, " ");
                }
                else{
                    printf("%2d", a[i]);
                    printf("%*s", 3," ");
                }
            }
            printf("\n"); 
            return binary_search(middle+1, right, key, a);
        }
    }
    return -1;
}