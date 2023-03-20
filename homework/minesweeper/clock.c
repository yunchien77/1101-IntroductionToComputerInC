#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
 
    clock_t start, end;
   
    // Start Record the time
    start = clock();
   
// Your program....

    // Record the end time
    end = clock();

    double diff = end - start; // ms
    printf(" %f  ms" , diff);
    printf(" %f  sec", diff / CLOCKS_PER_SEC );

    return 0;
}