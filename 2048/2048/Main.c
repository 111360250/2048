#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <time.h>
#include <windows.h>
int sum[4][4];	                                  //4*4的格子中所含的數字 
int checking = 0;	                                 //檢查是否還可以移動 
char ch;	                                                   //抓方向用 
char replay;	                                               //是否重玩 
int max = 0;	                                                 //最高分 
int score = 0;                                                     //分數 

void plus() {
    int i, j;	                                                   //座標 
    if (ch == 75)	                                  /*往左移動(小座標)*/
        for (i = 0; i < 4; i++)
            for (j = 0; j < 3; j++)
                if (sum[i][j] == sum[i][j + 1]) {
                    sum[i][j] += sum[i][j + 1];
                    sum[i][j + 1] = 0;
                    score += sum[i][j];
                }
    if (ch == 77)	                                  /*往右移動(大座標)*/
        for (i = 0; i < 4; i++)
            for (j = 3; j >= 0; j--)
                if (sum[i][j] == sum[i][j - 1]) {
                    sum[i][j] += sum[i][j - 1];
                    sum[i][j - 1] = 0;
                    score += sum[i][j];
                }
    if (ch == 72)	                                  /*往上移動(小座標)*/
        for (i = 0; i < 4; i++)
            for (j = 0; j < 3; j++)
                if (sum[j][i] == sum[j + 1][i]) {
                    sum[j][i] += sum[j + 1][i];
                    sum[j + 1][i] = 0;
                    score += sum[j][i];
                }
    if (ch == 80)	                                  /*往下移動(大座標)*/
        for (i = 0; i < 4; i++)
            for (j = 3; j >= 0; j--)
                if (sum[j][i] == sum[j - 1][i]) {
                    sum[j][i] += sum[j - 1][i];
                    sum[j - 1][i] = 0;
                    score += sum[j][i];
                }
}
int point() {
    int i, j;	                                                   //座標 

    for (i = 0; i < 4; i++)	                                  /*尋找是否有0*/
        for (j = 0; j < 4; j++)
            if (sum[i][j] == 0)
                checking++;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 3; j++)
            if (sum[i][j] == sum[i][j + 1])
                checking++;
    for (i = 0; i < 4; i++)
        for (j = 3; j >= 0; j--)
            if (sum[i][j] == sum[i][j - 1])
                checking++;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 3; j++)
            if (sum[j][i] == sum[j + 1][i])
                checking++;
    for (i = 0; i < 4; i++)
        for (j = 3; j >= 0; j--)
            if (sum[j][i] == sum[j - 1][i])
                checking++;
    if (checking == 0) {
        int i, j;	                                               //座標 
        printf("\n\n                                                    YOU LOSE!!!");
        Sleep(3000);
        system("cls");
        printf(" \n\n\n                                                  遊戲結束\n\n\n\n");
        printf("  當局分數:%d   最高分:%d\n\n\n\n", score, max);
        printf("是否重新開始(Y/N) ? ");
        scanf(" %c", &replay);
        if (replay == 'Y') {
            for (i = 0; i < 4; i++)	                             /*清空數字*/
                for (j = 0; j < 4; j++)
                    sum[i][j] = 0;
        }
        if (replay == 'N') {
            bye();
            return 0;
        }
    }
}
void reset() {
    int i, j;
    score = 0;
    for (i = 0; i < 4; i++)	                                     /*清空數字*/
        for (j = 0; j < 4; j++)
            sum[i][j] = 0;
}
int main(int argc, char* argv[])
{
    system("pause");;
}
