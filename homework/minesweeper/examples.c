#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 9
#define MAX_COL 9
#define MAX_MINE_NUM 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//選單函數
int menu(){
	printf("--------------\n");
	printf("1.開始遊戲\n");
	printf("2.退出遊戲\n");
	printf("--------------\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

//初始化兩張地圖
void initMap(char playerMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL]){
	//初始化playermap
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			playerMap[row][col] = '*';
		}
	}
	//初始化minemap
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			mineMap[row][col] = '0';
		}
	}
	//隨機生成10個雷(minemap)
	int mineNum = 0;
	while (mineNum<MAX_MINE_NUM){
		int row = rand() % 9;
		int col = rand() % 9;

		if (mineMap[row][col] == '0'){
			mineMap[row][col] = '1';
			mineNum++;
		}
	}
}

//列印地圖
void printMap(char theMap[MAX_ROW][MAX_COL]){
	printf("  |");
	for (int col = 0; col < MAX_COL; col++){
		printf("%d |", col);
	}
	printf("\n");
	printf("--+--+--+--+--+--+--+--+--+--+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("%d ", row);
		printf("|");
		for (int col = 0; col < MAX_COL; col++){
			printf("%c |", theMap[row][col]);
		}
		printf("\n");
		printf("--+--+--+--+--+--+--+--+--+--+\n");
	}
}


//改變玩家所見地圖資訊
void updateMapInfor(char playerMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL],int row, int col){
	//定義所選位置周圍的地雷的個數
	int numOfMine = 0;
	for (int r = row - 1; r <= row + 1; r++){
		for (int c = col - 1; c <= col + 1; c++){
			if (r >= 0 && r < MAX_ROW && c >= 0 && c < MAX_COL && mineMap[r][c] == '1'){
				numOfMine++;
			}
		}
	}
	playerMap[row][col] = numOfMine + '0';
}


//玩家操作,
//返回值代表玩家所選位置是否是雷
//是雷返回1，不是雷返回0
int playDo(char playerMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL]) {
	printf("輸入橫縱座標選擇沒有雷的位置,(橫 縱)\n");
	int row = 0;
	int col = 0;
	while (1){
		scanf("%d %d", &row, &col);
		if (playerMap[row][col] == '*' &&row >= 0 && row < MAX_ROW &&col >= 0 && col < MAX_COL) {
			//被選位置未被揭開,且被選位置沒有越界
			break;
		}
		printf("您的位置輸入有誤，可能存在如下問題\n");
		printf("1.位置選擇越界\n2.所選位置已經被揭開\n");
		printf("請您重新輸入位置\n");
	}
	//判斷是不是雷，如果是
	if (mineMap[row][col] == '1'){
		return 1;
	}
	else{//否則（不是雷）更新地圖資訊
		updateMapInfor(playerMap, mineMap, row, col);
		return 0;
	}
	
}

//判斷玩家是否勝利(所有雷是否已經被找完),返回值為1代表勝利，0代表還未勝利
//判斷方法為，檢查玩家地圖上未揭起的位置是否和雷的個數相等
//（可揭起的一定不是雷，未揭起的可能是雷）
//若未揭起的個數大於雷的個數說明遊戲還未結束
int isWin(char playerMap[MAX_ROW][MAX_COL]){
	//玩家地圖中草坪的個數，也就是未揭起位置的個數，初始化為0
	int numOfGrass = 0;
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			if (playerMap[row][col] == '*'){
				numOfGrass++;
			}
		}
	}
	if (numOfGrass == MAX_MINE_NUM){
		return 1;
	}
	return 0;
}

void game(){
	//玩家看見的地圖
	char playerMap[MAX_ROW][MAX_COL];
	//埋雷地圖
	char mineMap[MAX_ROW][MAX_COL];
	//1.初始化兩張地圖，
	//一張玩家看見的map1，草地全用*表示
	//一張地雷地圖map2，地雷的位置隨機生成，有雷為1，沒雷為0
	initMap(playerMap, mineMap);
	//2.列印map1
	printMap(playerMap);
	//TODO
	//printMap(mineMap);
	while (1){
		//3.玩家操作，輸入座標
		//判斷玩家選擇的位置是否是雷
		//若是則跳出迴圈結束
		if (playDo(playerMap, mineMap) == 1){
			printf("你輸了\n");
			break;
		}
		//判斷所有雷是否已經被找完
		//是，則遊戲勝利
		if (isWin(playerMap)==1){
			printf("你贏了\n");
			break;
		}
		//否，則繼續遊戲
		//4.列印map1
		printMap(playerMap);
	}
	//5.判斷遊戲是否結束，否回到3
	//6.是，遊戲結束，列印地雷位置圖
	printMap(mineMap);
}

int main(){
	//選單，1.開始遊戲   2.退出遊戲
	int choice = 0;
	srand((unsigned int)time(0));
	while (1){
		choice = menu();
		if (choice == 1){
			game();
			break;
		}
		else if (choice == 2){
			break;
		}
		else{
			printf("您的輸入有誤，請重新輸入\n");
		}
	}
	system("pause");
	return 0;
}