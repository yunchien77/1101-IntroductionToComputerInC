extern int ROW;
extern int COL;
extern int EASY_COUNT;//地雷個數
extern int surplus;//剩餘地雷個數

#define ROWS 18
#define COLS 32
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <assert.h>

void Init(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void getFastestTime(int *FastestTime);
void storeFastestTime(int FastestTime);

//功能選單
void menu()
{
    printf("***************************\n");
    printf("******** 1.play *********\n");
    printf("******** 0.exit *********\n");
    printf("***************************\n");
}

void menu1()
{
    printf("*** 1.simple 2.middle 3.diffcult ***\n");
}

void game()
{
    char mine[ROWS][COLS] = { 0 };//11*11
    char show[ROWS][COLS] = { 0 };
    //初始化
    Init(mine, ROWS, COLS, '0');
    Init(show, ROWS, COLS, '*');
    DisplayBoard(show,ROW,COL);
    SetMine(mine, ROW, COL);
    //DisplayBoard(mine, ROW, COL);
    FindMine(mine,show,ROW,COL);
}

extern int win;
int ROW = 10;
int COL = 10;
int EASY_COUNT = 15;
int surplus = 0; //剩余雷的个数

//使用者一開始輸入模式
void text()
{
    int input = 0;
    int input1 = 0;
    srand((unsigned int)time(NULL));
    do{
        menu();
        win = 0;
        printf("please select:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            menu1(); //使用者選擇模式
            printf("please select:>");
            scanf("%d", &input1);
            switch (input1)
            {
                case 1:
                    ROW = 10;
                    COL = 10;
                    EASY_COUNT = 15;
                    surplus = 15;
                    break;
                case 2:
                    ROW = 16;
                    COL = 16;
                    EASY_COUNT = 40;
                    surplus = 40;
                    break;
                case 3:
                    ROW = 16;
                    COL = 30;
                    EASY_COUNT = 99;
                    surplus = 99;
                    break;
            }
            game();
            break;
        case 0:
            printf("goodbye!\n");
            break;
        default:
            printf("input error, choose again!\n");
        }
    } while (input);
}

int main()
{
    text();
    return 0;
}

//初始化
void Init(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0, j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    printf("Number of surplus mines:%d\n",surplus);
    int i = 0, j = 0;
    for (i = 0; i <= col; i++)
    {
        printf("%3d", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%3d ", i);
        for (j = 1; j <= col; j++)
        {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

//設置地雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand() % (row - 1) + 1;//1-row
        int y = rand() % (col - 1) + 1;//1-col
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;//當count減至0則迴圈跳出
        }
    }
}

//計算周邊地雷總和
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1]- 8 * '0';
}

int win = 0;

void disp(char mine[ROWS][COLS], char show[ROWS][COLS], int x1, int y1)
{
    int arr[8][2] = { { x1 - 1, y1 - 1 }, { x1 - 1, y1 }, { x1 - 1, y1 + 1 }, { x1, y1 - 1 }, { x1, y1 + 1 }, { x1 + 1, y1 - 1 }, { x1 + 1, y1 }, { x1 + 1, y1 + 1 } };
    int i = 0;
    for (i = 0; i < 8; i++)
    {
        int x1 = arr[i][0], y1 = arr[i][1];
        if (x1 >= 1 && x1 <= ROW && y1 >= 1 && y1 <= COL && mine[x1][y1] == '0' && show[x1][y1] == '*')
        {
            int count = get_mine_count(mine, x1, y1);
            show[x1][y1] = count + '0'; //顯示周圍雷的個數
            win++;
            //若周圍無地雷，則展開
            if (mine[x1 - 1][y1 - 1] == '0' && mine[x1 - 1][y1] == '0' && mine[x1 - 1][y1 + 1] == '0' && mine[x1][y1 - 1] == '0' && mine[x1][y1 + 1] == '0' && mine[x1 + 1][y1 - 1] == '0' && mine[x1 + 1][y1] == '0' && mine[x1 + 1][y1 + 1] == '0')
            {
                show[x1][y1] = ' ';
                disp(mine, show, x1, y1);
            }
        }
    }
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0, y = 0,input=0;
    int times=0;
    double start,finish;
    while (win < row*col-EASY_COUNT)
    {
        printf("Please enter a coordinate and open 0 or mark/unmark 1 ( x, y, 0 or 1 ):>");
        scanf("%d %d %d", &x, &y, &input);
        assert(input==0||input==1);
        times=times+1;
        if (x >= 1 && x <= row && y >= 1 && y <= col )
        {
            if (input == 0) //排雷
            {
                if (mine[x][y] == '1') //踩雷
                {
                    printf("You have stepped on the thunder! game over!\n");
                    printf("Total time:%d\n",times);
                    finish = clock();//取結束時間
                    printf("elapsed time:%d sec\n", (int)(finish - start) / CLOCKS_PER_SEC);
                    DisplayBoard(mine, row, col);
                    break;
                }
                else //非雷
                {
                    //計算周圍有多少地雷
                    int count = get_mine_count(mine, x, y);
                    if (count == 0)
                    {
                        show[x][y] = ' ';
                    }
                    else
                    {
                        show[x][y] = count + '0';
                    }
                    win++;
                    if (mine[x - 1][y - 1] == '0' && mine[x - 1][y] == '0' && mine[x - 1][y + 1] == '0' && mine[x][y - 1] == '0' && mine[x][y + 1] == '0' && mine[x + 1][y - 1] == '0' && mine[x + 1][y] == '0' && mine[x + 1][y + 1] == '0')
                    {
                        disp(mine, show, x, y);
                    }
                }
            }
            else if (input == 1)
            {
                if (show[x][y] == '*')
                {
                show[x][y] = '!';
                surplus--;
                }
                else if (show[x][y] == '!')
                {
                    show[x][y] = '*';
                    surplus++;
                }
            }
            DisplayBoard(show, row, col);
        }
        else
        {
            printf("The coordinates are invalid, please re-enter:\n");
        }
    }
    if (win == row*col - EASY_COUNT)
    {
        printf("you win!!\n");
        printf("Total time:%d\n",times);
        finish = clock();//取結束時間
        printf("elapsed time:%d sec\n", (int)(finish - start) / CLOCKS_PER_SEC);
        DisplayBoard(mine, row, col);
        int FastestTime=0x3f3f3f3f;
        int elapstedtime=0x3f3f3f3f;
        getFastestTime(&FastestTime);
        printf("Original fastest time:%d\n",FastestTime);
        elapstedtime=(int)(finish - start) / CLOCKS_PER_SEC;
        if(elapstedtime<FastestTime)
            FastestTime=elapstedtime;
        printf("New fastest time:%d\n",FastestTime);
        storeFastestTime(FastestTime);
    }
}

void getFastestTime(int *FastestTime){
    FILE *fp=NULL;
    fp=fopen("FastestTime.txt","r");
    if(fp==NULL){
        fp=fopen("FastestTime.txt","w");
        fprintf(fp,"%-10d",*FastestTime);
    }
    else
        fscanf(fp,"%10d",FastestTime);
    fclose(fp);
}

void storeFastestTime(int FastestTime){
    FILE * fp=NULL;
    fp=fopen("FastestTime.txt","w");
    fprintf(fp,"%-10d",FastestTime);
    fclose(fp);
}