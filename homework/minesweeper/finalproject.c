#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ROW 10
#define MAX_COL 10
#define MAX_MINE 15
int playermap[MAX_ROW][MAX_COL];
int minesmap[MAX_ROW][MAX_COL];

//菜單
void menu(){
    int INmenu = 0;
    printf("\t歡迎來到\"踩地雷\"遊戲！\n");
    printf("----------------------------------------\n");
    printf("\t請選擇:\n");
    printf("\t1: 開始遊戲\n\t2: 退出遊戲\n");
    scanf("%d", &INmenu);
    switch (INmenu)
    {
    case 1:
        printf("遊戲開始!");
        for(int i=0; i<MAX_COL; i++){
            printf("%3d", i);
        }
        printf(" X");
        printf("\n");
    
        for(int i=0; i<MAX_COL; i++){
            printf("%d", i);
            printf("%*s", 1, " ");
            printf("■  ■  ■  ■  ■  ■  ■  ■  ■  ■\n");
        }
        printf("Y\n");
        break;
    case 2:
        exit(0);
    default:
        printf("輸入的數字有誤\n請再輸入一次\n");
        return menu();
    }
}

//初始化及產生隨機地雷
void randMINES(int minesmap[MAX_ROW][MAX_COL], int playermap[MAX_ROW][MAX_COL]){
    //初始化地雷地圖為零，玩家地圖為5
    for(int i=0; i<MAX_ROW; i++){
        for(int j=0; j<MAX_COL; j++){
            minesmap[i][j] == 0;
            playermap[i][j] == 5;
        }
    }
    //產生隨機地雷
    int mines = 0;
    srand(time(NULL));
    while(mines < MAX_MINE){
        //隨機產生數字0~8
        int row = rand() % 9;
        int col = rand() % 9;
        //隨機位置'0'覆寫成'1'
        if(minesmap[row][col] == 0){
            minesmap[row][col] = 1;
            mines++;
        }
    }
}

//列印遊戲畫面
void print_MAP(int MAP[MAX_ROW][MAX_COL]){
    for(int i=0; i<MAX_COL; i++){
        printf("%3d", i);
    }
    printf(" X");
    printf("\n");
    
    for(int i=0; i<MAX_ROW; i++){
        printf("%d", i);
        printf("%*s", 1, " ");
        for(int j=0; j<MAX_COL; j++){
            printf("%d", MAP[i][j]);
        }
    }
    printf("Y\n");
}

//更新地圖，計算周圍個數
void countmines(int playermap[MAX_ROW][MAX_COL], int minesmap[MAX_ROW][MAX_COL], int row, int col){
    int minesNUM = 0;
    for(int i = row-1; i <= row+1; i++){
        for(int j = col-1; j <= col+1; j++){
            if(i<0 || i>=MAX_ROW && j>=MAX_COL && j<0){
                continue;
            }
            if(i == row && j == col){
                continue;
            }
            if(i>=0 && i<MAX_ROW && j<MAX_COL && j>=0 && minesmap[i][j] == 1){
                minesNUM++;
            }
            
        }
    }
    playermap[row][col] = minesNUM;
}

void game(){
    randMINES(minesmap, playermap);
    print_MAP(playermap);
}

int main(){
    
    menu();
    return 0;
}

