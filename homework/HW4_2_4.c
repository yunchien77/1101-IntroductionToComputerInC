#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int menu(){
    int DOorNOT;
    printf("-------------------   -1: end the game    -------------------\n");
    printf("-------------------   1: start the game   -------------------\n");
    scanf("%d", &DOorNOT);

    return DOorNOT;
}

int game(){
    srand(time (NULL) );
    int rnum = rand() % 100 + 1;
    int gtime = 1, max = 100, min = 1;

    while(1){
        int gnum;
        printf("Please type your guess:\n");
        scanf("%d", &gnum);

        if(gnum < 1 || gnum > 100){
            printf("Your number is out of range.\n");
            continue;
        }
        else if(gnum == rnum){
            printf("Excellent! You took %d times to guess my number!\n", gtime);
            printf("Would you like to play again?\n");
            break;
        }
        else{
            if(gnum < rnum){
                gtime += 1;
                min = gnum;
                printf("Too low. The answer is in the range of %d ~ %d. Try again.\n", min, max);
                continue;
            }
            else if(gnum > rnum){
                gtime += 1;
                max = gnum;
                printf("Too high. The answer is in the range of %d ~ %d. Try again.\n", min, max);
                continue;
            }
        }
    }
    return 0;
}


int main(){
    int DOorNOT = menu();
    switch(DOorNOT){
    case 1:
        printf("WELCOME! This is the game of \"GUESS THE NUMBER\"\n");
        printf("I have a number between 1 and 100\n");
        printf("Can you guess my number?\n");
        game();
        main();
        break;
    case -1:
        printf("bye bye\n");
        break;
    default:
        printf("please type 1 to start the game or you can type -1 to end this game.\n");
        main();
    }
    return 0;
}
