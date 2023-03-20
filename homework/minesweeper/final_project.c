#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 10
#define MAX_COL 10
#define MAX_MINE 15

int playermap[MAX_ROW + 2][MAX_COL + 2] = {0}, minesmap[MAX_MINE] = {0}, map[MAX_ROW + 2][MAX_COL + 2] = {0};
int k, minesNum;
int x, y, z, step, ALL_MINE;
clock_t start, end;

void menu();
void game();
void type();
void printMAP();
void initialmap();
int select(int,int);

int main()
{
    ALL_MINE = 100;
    menu();
    initialmap();
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            printf(" %d", playermap[i][j]);
        }
        printf("\n");
    }
    while(1){
        game();
        if(ALL_MINE == 15){
            end = clock();
            break;
        }
    }
    printf("遊戲結束!");
    printf("恭喜勝利!");
    printf("您用了%d步", step);
    double diff = end - start;
    printf("遊戲所用時間: %f sec", diff / CLOCKS_PER_SEC);
    return 0;
}

void menu(){
    int INmenu = 0;
    printf("\t歡迎來到\"踩地雷\"遊戲！\n");
    printf("----------------------------------------\n");
    printf("\t1: 開始遊戲\n\t2: 退出遊戲\n\n");
    printf("\t請選擇遊戲清單:");
    scanf("%d", &INmenu);
    printf("----------------------------------------\n");
    switch (INmenu)
    {
    case 1:
        printf("\t遊戲開始!\n");
        printf("----------------------------------------\n");
        for(int i=0; i<MAX_COL; i++){
            printf("%3d", i);
        }
        printf(" X");
        printf("\n");
    
        for(int i=0; i<MAX_COL; i++){
            printf("%d", i);
            printf("%*s", 1, " ");
            printf("■  ■  ■  ■  ■  ■  ■  ■  ■  ■\n");
            start = clock();
        }
        printf("Y\n");
        break;
    case 2:
        exit(0);
    default:
        printf("\t輸入的數字有誤，請再輸入一次\n\n");
        return menu();
    }
} 

int select(int i,int r){
        int k = 0;
        while(k < i){
            if(minesmap[k] == r){
                r = (rand()% 100) + 1;
                r = select(i,r);
                break;
            }
            else{
                k++;
            }
        }
        return r; 
}

void initialmap(){
    //get 棋盤數列(playermap)
    k = 1;
    for(int i = 0; i < MAX_ROW + 2; i++){
        for(int j = 0; j < MAX_COL + 2; j++){
            if(i == 0 || i == MAX_ROW + 1){
                playermap[i][j] = 0;
            }
            else if(j == 0 || j == MAX_COL + 1){
                playermap[i][j] = 0;
            }
            else{
                playermap[i][j] = k;
                k++;
            }
        }
    }

    //get 地雷數列
    for(int i = 0; i < 15; i++){
        srand((unsigned)time(NULL));
        int r = (rand()% 100) + 1;
        minesmap[i] = select(i,r);
    }

    //畫地雷(地雷 = -1)
    for(int i = 0; i < MAX_ROW + 2; i++){
        for(int j = 0; j < MAX_COL + 2; j++){
            //看是不是地雷
            for(int k = 0; k < MAX_MINE; k++){
                if((playermap[i][j]) == minesmap[k]){
                    playermap[i][j] = -1;
                }
            }
        }
    }

    //畫數字
    for(int i = 1; i < MAX_ROW + 1; i++){
        for(int j = 1; j < MAX_COL + 1; j++){
            minesNum = 0;
            //搜尋周圍
            if((playermap[i][j]) != -1){
                for(int k = i - 1; k <= i + 1 ; k++){
                    for(int w = j - 1; w <= j + 1; w++){
                        if((playermap[k][w]) == -1){
                            minesNum ++;
                        }
                    }
                }   
                playermap[i][j] = minesNum;
            }
        }
    }
    
    //設map初始陣列
    for(int i = 0; i < MAX_ROW + 2; i++){
        for(int j = 0; j < MAX_COL + 2; j++){
            map[i][j] = 10;
        }
    }
}   

void game(){
    printf("功能: 1. 打開位置  2. 標記/取消標記\n");
    printf("請輸入座標與動作(X, Y, 功能):");
    scanf("%d%d%d", &x, &y, &z);
    if(z == 1){
        type();    
        printMAP();
        printf("步數:%d\n剩餘地雷個數:%d\n\n", step, ALL_MINE);    
    }
    else if(z == 2){
        if((map[x][y]) == 10){
            map[x][y] = 9;
        }
        else{
            map[x][y] = 10;
        }
        step++;
        printMAP();
        printf("步數:%d\n剩餘地雷個數:%d\n\n", step, ALL_MINE); 
    }
    else{
        printf("\n!!!錯誤的動作!!!\n請再輸入一次");
        return game(); 
    }
}

void type(){
    if(map[x][y] != 10){
        printf("操作錯誤請再試一次\n");
    }
    else if(playermap[x][y] == -1){
        for(int i = 1; i < MAX_COL+1; i++){
            printf("%3d", i-1);
        }
        printf(" X");
        printf("\n");

        for(int j = 1; j < MAX_COL+1; j++){
            printf("%d", j-1);
            for(int i = 1; i < MAX_ROW+1; i++){
                if(playermap[i][j] == -1){
                    printf(" * ");
                }
                else if(map[i][j] == 9){
                    printf(" P ");
                }
                else if((map[i][j])!= 10){
                    printf(" %d ", (map[i][j]));
                }
                else{
                    printf(" ■ ");
                }
            }
            printf("\n");
        }
        printf("Y\n");
        step++;
        printf("遊戲結束\n");
        end = clock();
        printf("您用了%d步\n", step);
        double diff = end - start;
        printf("遊戲所用時間: %f sec", diff / CLOCKS_PER_SEC);
        exit(0);
    }
    else{
        step++;
        map[x][y] = playermap[x][y];
        ALL_MINE--;
    }
}

void printMAP(){
    for(int i = 1; i < MAX_COL+1; i++){
        printf("%3d", i-1);
    }
    printf(" X");
    printf("\n");
    
    for(int j = 1; j < MAX_COL+1; j++){
        printf("%d", j-1);
        for(int i = 1; i < MAX_ROW+1; i++){
            if((map[i][j]) == 9){
                printf(" P ");
            }
            else if((map[i][j] != 10)){
                printf(" %d ", (playermap[i][j]));
            }
            else{
                printf(" ■ ");
            }
        }
        printf("\n");
    }
    printf("Y\n");
}