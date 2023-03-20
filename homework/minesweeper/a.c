#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>

#define MAX_ROW 10
#define MAX_COL 10
#define MAX_MINE 15

int playermap[MAX_ROW + 2][MAX_COL + 2] = {0}, minesmap[MAX_MINE] = {0}, map[MAX_ROW + 2][MAX_COL + 2] = {0}; 
int k, r, minesNum;
int x, y, z, step, ALL_MINE;
clock_t start, end; //宣告時間變數

int selectmines(int,int);
void menu();
void game();
void type();
void printMAP();
void initialmap();
void SetColor(int color);

int main()
{
    ALL_MINE = 100;
    menu();
    initialmap();
    while(1){
        game();
        if(ALL_MINE == 15){
            end = clock();
            break;
        }
    }
    SetColor(14);
    printf("遊戲結束!");
    printf("恭喜勝利!");
    printf("您用了%d步", step);
    double diff = end - start;
    printf("遊戲所用時間: %f sec", diff / CLOCKS_PER_SEC);
    SetColor(7);
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
            printf("%3d", i + 1);
        }
        printf(" X");
        printf("\n");
    
        for(int i=0; i<MAX_COL; i++){
            printf("%d", i + 1);
            printf("%*s", 1, " ");
            printf("■  ■  ■  ■  ■  ■  ■  ■  ■  ■\n");
        }
        printf("Y\n");

        start = clock(); //紀錄時間(開始)
        break;
    case 2:
        exit(0);
    default:
        SetColor(12);
        printf("\t輸入的數字有誤！請再輸入一次！\n\n");
        SetColor(7);
        return menu();
    }
} 

void initialmap(){
    //get 棋盤數列(playermap)
    k = 1;
    for(int i = 1; i < MAX_ROW + 1; i++){
        for(int j = 1; j < MAX_COL + 1; j++){
            playermap[i][j] = k;
            k++;
        }
    }
    //test
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            printf(" %d ", (playermap[i][j]));
        }
        printf("\n");
    }

    //get 地雷數列
    for(int i = 0; i < 15; i++){
        srand((unsigned int)time(NULL));
        r = (rand()% 100) + 1;
        minesmap[i] = selectmines(i,r);
    }
    //test
    for(int i = 0; i < 15; i++){
        printf("%d ", minesmap[i]);
    }

    printf("\n");

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

    //計算周圍地雷數，更新地圖
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

    //test
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            printf(" %d", playermap[i][j]);
        }
        printf("\n");
    }

    //test 確認地雷數是否為15
    int k = 0;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
                if((playermap[i][j]) == -1){
                    k++;
                }
        }
    }
    printf("%d*\n" , k);

    //test
    for(int i=0; i<12; i++){
        for(int j=0; j<12; j++){
            printf(" %d", playermap[i][j]);
        }
        printf("\n");
    }

    //設map初始陣列
    for(int i = 1; i < MAX_ROW + 1; i++){
        for(int j = 1; j < MAX_COL + 1; j++){
            map[i][j] = 10;
        }
    }
}  

int selectmines(int i, int r){
    int k = 0;
    while(k < i){
        if(minesmap[k] == r){
            r = (rand()% 100) + 1;
            r = selectmines(i, r);
            break;
        }
        else{
            k++;
        }
    }
    return r;
}

void game(){
    SetColor(10);
    printf("功能: 1. 打開位置  2. 標記/取消標記\n");
    printf("請輸入座標與動作(X, Y, 功能):");
    scanf("%d%d%d", &x, &y, &z);
    SetColor(7);
    if(z == 1){
        type();    
        printMAP();
        SetColor(13);
        printf("步數:%d\n剩餘地雷個數:%d\n\n", step, ALL_MINE);    
        SetColor(7);
    }
    else if(z == 2){
        if((map[x][y]) == 10){
            map[x][y] = 9;
            step++;
        }
        else if((map[x][y]) == 9){
            map[x][y] = 10;
            step++;
        }
        else{
            SetColor(12);
            printf("\n!!!錯誤的動作!!!請再輸入一次\n");
            SetColor(7);
            return game(); 
        }
        printMAP();
        SetColor(13);
        printf("步數:%d\n剩餘地雷個數:%d\n\n", step, ALL_MINE); 
        SetColor(7);
    }
    else{
        SetColor(12);
        printf("\n!!!錯誤的動作!!!請再輸入一次\n");
        SetColor(7);
        return game(); 
    }
}

void type(){
    if(map[x][y] != 10){
        SetColor(12);
        printf("操作錯誤請再試一次\n");
        SetColor(7);
    }
    else if(playermap[x][y] == -1){
        for(int i = 0; i < MAX_COL; i++){
            printf("%3d", i+1);
        }
        printf(" X");
        printf("\n");

        for(int j = 1; j < 11; j++){
            printf("%d", j);

            for(int i = 1; i < 11; i++){
                if(playermap[i][j] == -1){
                    SetColor(11);
                    printf(" * ");
                    SetColor(7);
                }
                else if(map[i][j] == 9){
                    SetColor(12);
                    printf(" P ");
                    SetColor(7);
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
        SetColor(14);
        printf("遊戲結束\n");
        end = clock();
        printf("您用了%d步\n", step);
        double diff = end - start;
        printf("遊戲所用時間: %.2f sec", diff / CLOCKS_PER_SEC);
        SetColor(7);
        exit(0);
    }
    else{
        step++;
        map[x][y] = playermap[x][y];
        ALL_MINE--;
    }
}

void printMAP(){
    for(int i = 0; i < MAX_COL; i++){
        printf("%3d", i + 1);
    }
    printf(" X");
    printf("\n");
    
    for(int j = 1; j < 11; j++){
        printf("%d", j);
        for(int i = 1; i < 11; i++){
            if((map[i][j]) == 9){
                SetColor(12);
                printf(" P ");
                SetColor(7);
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


void SetColor(int color)
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}