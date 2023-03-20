#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    printf("WELCOME! This is the game of \"GUESS THE NUMBER\"\n");
    printf("I have a number between 1 and 100\n");
    printf("Can you guess my number?\n");

    srand( time(NULL) );    //設定亂數種子
    int r = rand() % 101;   //產生範圍0到100的亂數

    int count = 1;

    while(count >= 1){
        int guess;
        printf("Please type your guess (enter -1 to end):\n");
        scanf("%d", &guess);

        if(r > guess && guess != -1){
            printf("Too low. Try again.\n");
        }
        else if(r < guess && guess != -1){
            printf("Too high. Try again.\n");
        }
        else if(r == guess && guess != -1){
            int num;
            printf("Excellent! You took %d times to guess my number!\n", count);
            printf("Would you like to play again? (Type 1 to restart a new game, -1 to end)\n");
            scanf("%d", &num);

            if(num == 1){   //num輸入1則重新開始遊戲
                main();     //回到主程式
            }
            break;
        }
        else{               //當guess輸入為1則跳出迴圈
            break;
        }
        count++;
    }
    return 0;
}
