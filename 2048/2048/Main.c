#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
#include <time.h>
#include <windows.h>

int sum[4][4];	                                  //4*4����l���ҧt���Ʀr 
int num[4][4];									//�ˬd�O�_������ 
int over;
int temp[8] = { 2,2,2,2,2,2,2,4 };
char ch;
int max = 0;	                                                 //�̰��� 
int score = 0;
void square()
{
	system("cls");	                    /*�M�ŵe���A���s���e�����л\�ª�*/
	int i, j;	                                                 //�j���
	int k = 0;
	printf("\n\n\n  �̰�����:%d   ��e����:%d\n", max, score);
	/*�L�X4*4��l*/
	printf("\n\n----------------------------\n");
	for (i = 0; i < 4; i++) {
		printf("                                          |");
		for (j = 0; j < 4; j++)
		{
			if (sum[i][j] == 0)	                /*�p�G�y�Ь�0�ɤ��L�Ʀr*/
				printf("     | ");
			else
				printf("%4d | ", sum[i][j]);
		}
		printf("\n----------------------------\n");
	}
	printf("\n  ���s�}�l�Ы��ť���\n");
	for (i = 0; 4 > i; i++)
		for (j = 0; 4 > j; j++)
		{
			if (sum[i][j] > 0)
				k++;
		}
	if (k >= 16)
	{
		printf("\n\n�[�o��!����!");
	}
	printf("\n\n\n�խ�:���l޳");
	printf("\n���a��");
	printf("\n���v��");
}
void copy()
{
	int i, j, k;	                                          //�y�� / �j���
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			num[i][j] = sum[i][j];
}
void lave() {	                 //�Y�Ѿl���ŭӼƤp��w�]�ͦ��ƥi�~��ͦ� 
	int i, j;
	over = 0;
	for (j = 0; 4 > j; j++)
		for (i = 0; 4 > i; i++)
			if (sum[i][j] == 0)
				over++;

}
void move() {
	int i, j, k;	                                          //�y�� / �j��� 
	int temp;                                               //�Ȧs�Ʀr 

	if (ch == 75)	                                  /*��������(�p�y��)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[i][j] == 0 && sum[i][j + 1] > 0) {
						temp = sum[i][j];
						sum[i][j] = sum[i][j + 1];
						sum[i][j + 1] = temp;
					}
	if (ch == 77)	                                  /*���k����(�j�y��)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[i][j + 1] == 0 && sum[i][j] > 0) {
						temp = sum[i][j + 1];
						sum[i][j + 1] = sum[i][j];
						sum[i][j] = temp;
					}
	if (ch == 72)	                                  /*���W����(�p�y��)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[j][i] == 0 && sum[j + 1][i] > 0) {
						temp = sum[j][i];
						sum[j][i] = sum[j + 1][i];
						sum[j + 1][i] = temp;
					}
	if (ch == 80)	                                 /*���U����(�j�y��)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[j + 1][i] == 0 && sum[j][i] > 0) {
						temp = sum[j][i];
						sum[j][i] = sum[j + 1][i];
						sum[j + 1][i] = temp;
					}
	for (i = 0; i < 4; i++)	                                   /*�M��̤j��*/
		for (j = 0; j < 4; j++)
			if (score > max)
				max = score;
}



/*
	��L(�W) 72
	��L(�U) 80
	��L(��) 75
	��L(�k) 77

�y��(sum[i][j]):
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