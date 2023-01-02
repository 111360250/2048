#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <time.h>
#include <windows.h>

int sum[4][4];												   //4*4的格子中所含的數字 
int temp[8] = { 2,2,2,2,2,2,2,4 };	                           //7:1陣列 
char replay;	                                               //是否重玩 
int max = 0;	                                               //最高分 
int score = 0;                                                 //分數 
int hard;													   //遊戲難度 

void start()
{
	int i, j, k = 0;
	printf("\n\n\n\n\n\n歡迎來到2048!");
	printf("\n\n\n 請選擇遊戲難度(每次移動生成幾個數)\n");
	printf("\n建議 1 或 2 (不可大於5) : ");
	scanf("%d", &hard);
	while (hard > 5)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n歡迎來到2048!");
		printf("\n\n\n太難了!!!!!!!!!!\n");
		printf("\n\n 請重新輸入(不可大於5) : ");
		scanf("%d", &hard);
	}
	if (hard > 2)
		printf("\n大於2可能倒置遊戲難度過大!請做好準備!\n\n");
	Sleep(800);
	printf("\n\n 組員:");
	Sleep(1000);
	printf("黃泓瑋\n    董家典\n      蕭宗賓\n");
	Sleep(3000);
	system("cls");
	for (j = 1; 3 >= j; j++)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n ");
		Sleep(400);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n    遊戲開始!");
		Sleep(650);
	}
	Sleep(500);
}
void restart()                                    //重新開始時的輸入畫面
{
	system("cls");
	printf("\n\n\n\n\n\n\n請選擇遊戲難度(每次移動生成幾個數)\n");
	printf("\n\n建議 1 或 2 (不可大於5) : ");
	scanf("%d", &hard);
	while (hard > 5)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n太難了!!!(不可大於5)!!!!!!!\n");
		printf("\n\n      請重新輸入 : ");
		scanf("%d", &hard);
	}
	if (hard > 2)
		printf("\n\n 大於2可能倒置遊戲難度過大!請做好準備!\n\n");
	Sleep(1000);
	system("cls");
}
void bye()
{
	int i, j, k;
	for (i = 1; 8 >= i; i++)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("                                ");
		printf("BYE!!!BYE!!!");
		Sleep(100);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("                                             ");
		printf("BYE!!!BYE!!!");
		Sleep(100);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("                                                            ");
		printf("BYE!!!BYE!!!");
		Sleep(100);
		system("cls");
	}
}
void putin() {
	srand(time(NULL));
	int i, j;	                                       //用亂數選擇的座標
	int k;	                   //決定填入2或4 /*7:1的概率填入2或4*/                                        
	while (1)	                         /*座標為0時才會填入數字並跳出*/
	{
		i = rand() % 4;
		j = rand() % 4;
		k = rand() % 8;
		if (temp[k] == 2 && sum[i][j] == 0)
		{
			sum[i][j] = 2;
			break;
		}
		if (temp[k] == 4 && sum[i][j] == 0)
		{
			sum[i][j] = 4;
			break;
		}
	}
}
int main()
{
	system("pause");
	return 0;
}