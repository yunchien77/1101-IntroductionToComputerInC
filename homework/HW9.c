#include<stdio.h>
void sort(int*, int*, int*);
int main(){
    //將預設好的數字由大到小排序後印出
    int a = 9, b = 10, c = 8;
    sort(&a, &b, &c);
    printf("Descending order of a, b, c: %d, %d, %d\n", a, b, c);
    //將使用者輸入的數字由大到小排序後印出
    printf("Enter your own three values:\n");
    scanf("%d%d%d", &a, &b, &c);
    sort(&a, &b, &c);
    printf("Descending order of entered three values: %d, %d, %d\n", a, b, c);
    return 0;
}
void sort(int *a, int*b, int*c){
    int temp;
    if(*a < *b){
        temp = *a; *a = *b; *b = temp;
    }
    if(*a < *c){
        temp = *a; *a = *c; *c = temp;
    }
    if(*b < *c){
        temp = *b; *b = *c; *c = temp;
    }
}