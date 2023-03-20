#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int DoOrNot = 1;
    do{
        printf("WELCOME! This is the game of \"GUESS THE NUMBER\"\n");
        printf("I have a number between 1 and 100\n");
        printf("Can you guess my number?\n");

        srand(time (NULL));  //設定亂數種子
        int rnum = rand() % 100 + 1;  //產生範圍1~100的亂數
        int gNum, gtime = 1, min = 1, max = 100;

        while(1){
            printf("Please type your guess (enter -1 to end):\n");
            scanf("%d", &gNum);
            if(gNum == -1) {  //若輸入-1，則結束遊戲
                DoOrNot = 0; 
                break;
            }
            else if(gNum < 1 || gNum > 100){  //若輸入數字不在亂數範圍，則須重新輸入
                printf("Your number is out of range.\n"); 
                continue;
            }
            else {
                if(gNum == rnum){
                    printf("Excellent! You took %d times to guess my number!\n", gtime);
                    printf("Would you like to play again? (Type 1 to restart a new game, -1 to end)\n");
                    int k;
                    scanf("%d", &k);
                    if(k == 1) { 
                        break;
                    }
                    if(k == -1) {
                        DoOrNot = 0; 
                        break;
                    }
                }
                else if(gNum < rnum){
                    gtime += 1;
                    min = gNum;
                    printf("Too low. The answer is in the range of %d ~ %d. Try again.\n", min, max);
                    continue;
                }
                else{
                    gtime += 1;
                    max = gNum;
                    printf("Too high. The answer is in the range of %d ~ %d. Try again.\n", min, max);
                    continue;
                }
            }
        }
    }while(DoOrNot == 1);
    printf("----------------Bye Bye----------------");
    return 0;
}