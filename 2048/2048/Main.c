#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <time.h>
#include <windows.h>

int sum[4][4];	                                  //4*4的格子中所含的數字 
int num[4][4];									//檢查是否有移動 
int over;
int temp[8] = { 2,2,2,2,2,2,2,4 };
char ch;
int max = 0;	                                                 //最高分 
int score = 0;
void square()
{
	system("cls");	                    /*清空畫面，讓新的畫面能覆蓋舊的*/
	int i, j;	                                                 //迴圈用
	int k = 0;
	printf("\n\n\n  最高紀錄:%d   當前分數:%d\n", max, score);
	/*印出4*4格子*/
	printf("\n\n----------------------------\n");
	for (i = 0; i < 4; i++) {
		printf("                                          |");
		for (j = 0; j < 4; j++)
		{
			if (sum[i][j] == 0)	                /*如果座標為0時不印數字*/
				printf("     | ");
			else
				printf("%4d | ", sum[i][j]);
		}
		printf("\n----------------------------\n");
	}
	printf("\n  重新開始請按空白鍵\n");
	for (i = 0; 4 > i; i++)
		for (j = 0; 4 > j; j++)
		{
			if (sum[i][j] > 0)
				k++;
		}
	if (k >= 16)
	{
		printf("\n\n加油啊!肉雞!");
	}
	printf("\n\n\n組員:黃泓瑋");
	printf("\n董家典");
	printf("\n蕭宗賓");
}
void copy()
{
	int i, j, k;	                                          //座標 / 迴圈用
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			num[i][j] = sum[i][j];
}
void lave() {	                 //若剩餘的空個數小於預設生成數可繼續生成 
	int i, j;
	over = 0;
	for (j = 0; 4 > j; j++)
		for (i = 0; 4 > i; i++)
			if (sum[i][j] == 0)
				over++;

}
void move() {
	int i, j, k;	                                          //座標 / 迴圈用 
	int temp;                                               //暫存數字 

	if (ch == 75)	                                  /*往左移動(小座標)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[i][j] == 0 && sum[i][j + 1] > 0) {
						temp = sum[i][j];
						sum[i][j] = sum[i][j + 1];
						sum[i][j + 1] = temp;
					}
	if (ch == 77)	                                  /*往右移動(大座標)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[i][j + 1] == 0 && sum[i][j] > 0) {
						temp = sum[i][j + 1];
						sum[i][j + 1] = sum[i][j];
						sum[i][j] = temp;
					}
	if (ch == 72)	                                  /*往上移動(小座標)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[j][i] == 0 && sum[j + 1][i] > 0) {
						temp = sum[j][i];
						sum[j][i] = sum[j + 1][i];
						sum[j + 1][i] = temp;
					}
	if (ch == 80)	                                 /*往下移動(大座標)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[j + 1][i] == 0 && sum[j][i] > 0) {
						temp = sum[j][i];
						sum[j][i] = sum[j + 1][i];
						sum[j + 1][i] = temp;
					}
	for (i = 0; i < 4; i++)	                                   /*尋找最大數*/
		for (j = 0; j < 4; j++)
			if (score > max)
				max = score;
}



/*
	鍵盤(上) 72
	鍵盤(下) 80
	鍵盤(左) 75
	鍵盤(右) 77

座標(sum[i][j]):
	00	01	02	03
	10	11	12	13
	20	21	22	23
	30	31	32	33
*/
int main()
{
	system("pause");
	return 0;
}