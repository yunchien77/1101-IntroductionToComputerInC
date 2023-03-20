#include<stdio.h>
int main()
{
    double price, salary;
    printf("please enter hourly rate of worker($00.00):\n");
    scanf("%lf", &price);

    int worker = 1;

    while(worker <= 4){
        int hour;
        printf("please enter the working hours(-1 to end):\n");
        scanf("%d", &hour);

        if(hour <= 40 && hour != -1){
            salary = hour * price;
            printf("Salary is $%.2f\n", salary);
        }
        else if(hour > 40 && hour != -1){
            salary = 40 * price + (hour - 40)*1.5* price;
            printf("Salary is $%.2f\n", salary);
        }
        else{
            printf("while end\n");
        }
        worker++;
    }

    return 0;
}