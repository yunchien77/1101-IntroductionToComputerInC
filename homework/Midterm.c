#include<stdio.h>
int judge_number(int);
void print_element(int, int, int, int, int a[]);
int main(){
    int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28};
    int size = sizeof(arr) / sizeof(int);
    int key, i;

    while(1){
        //the user inputs which number need to be searched
        printf("Enter a number between 0 and 28: ");
        scanf("%d", &key);
        //judge the key whether between 0 and 28
        if(judge_number(key) == 1){
            break;
        }
    }
    printf("\nSubscripts:\n");
    //print the index of each element
    for(i=0; i<size; i++){
        printf("%2d", i);
        printf("%*s", 3, " ");
    }
    printf("\n-------------------------------------------------------------------------\n");

    int left = 0, right = size-1;  //left等同索引值0，right等同索引值size-1
    int middle = left + (right - left) / 2;  //取中間值，middle = (left + right)/2
    int find_index = 0;

    //print array
    print_element(i, left, right, middle, arr);
    printf("\n");
    
    //binary search
    do{
        if(key < arr[middle]){
            right = middle - 1;
            middle = left + (right - left) / 2;
            print_element(i, left, right, middle, arr);
        }
        else if(key > arr[middle]){
            left = middle + 1;
            middle = left + (right - left) / 2;
            print_element(i, left, right, middle, arr);
        }
        else{
            find_index = middle;
            break;
        }
        printf("\n");
    }while(left<=right);
    //if the number isn't existed, print not found
    if(find_index == 0){
        printf("%d not found", key);
    }
    //print the index where the number be searched
    else{
        printf("\n%d found in array element %d", key, middle);
    }
    return 0;
}

int judge_number(int num){
    if(num<0 || num>28){
        printf("\nThe number that you enter is out of range. Please enter again.\n\n");
        return 0;
    }
    return 1;
}

void print_element(int i, int left, int right, int middle, int a[]){
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
}