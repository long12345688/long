#define _CRT_SECURE_NO_WARINGS 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define ROWS 3//���ú������̴�С�����޸�
#define COLS 3
 
void init(char arr[ROWS][COLS])//���̳�ʼ��
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		
		for (j = 0; j < COLS; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
 
void print(char arr[ROWS][COLS])//��ӡ����
{
	system("cls");
	for (int row = 0; row < ROWS; row++) {
		printf("+---+---+---+\n");
		for (int col = 0; col < COLS; col++) {
			printf("| %c ", arr[row][col]);
		}
		printf("|");
		printf("\n");
	}
	printf("+---+---+---+\n");
	
}
 
void player(char arr[ROWS][COLS])//�����庯��
{
	int m, n;
	flag:
	printf("��������Ҫ�ߵ�λ�ã�");
	scanf_s("%d %d", &m, &n);
	if (arr[m - 1][n - 1] == ' ')
	{
		 arr[m - 1][n - 1] = 'X';
	}
	else
	{
		printf("��λ����������,��Ч\n");
		goto flag;
	}
	print(arr);
}
 
void computer(char arr[ROWS][COLS])//��������
{
	int line = 0;
	int column = 0;
	int count = 0;
	printf("�������壡��\n");
	while (1)
	{
		srand((unsigned)time(NULL));
		line = rand() % ROWS;
		column = rand() % COLS;
		if (arr[line][column] == ' ')
		{
			arr[line][column] = 'O';
				break;
		}
	}
	print(arr);
}
 
int full(char arr[ROWS][COLS])//�ж������Ƿ�����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			if (arr[i][j] == ' ')
				return 1;
		}
	}
	return 0;
}
 
int judge(char arr[ROWS][COLS])//�ж�˭Ӯ�ˣ�����ƽ��
{
	int i = 0;
	if ((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]))
	{
		if (arr[1][1] == 'X')
		{
			return 1;
		}
		if (arr[1][1] == 'O')
		{
			return -1;
		}
	}
	if ((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]))
	{
		if (arr[1][1] == 'X')
		{
			return 1;
		}
		if (arr[1][1] == 'O')
		{
			return -1;
		}
	}
	for (i = 0; i < ROWS; i++)
	{
		if ((arr[i][1] == arr[i][0]) && (arr[i][1] == arr[i][2]))
		{
			if (arr[i][1] == 'X')
			{
				return 1;
			}
			if (arr[i][1] == 'O')
			{
				return -1;
			}
		}
 
	}
	for (i = 0; i < COLS; i++)
	{
		if ((arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]))
		{
			if (arr[0][i] == 'X')
			{
				return 1;
			}
			if (arr[0][i] == 'O')
			{
				return -1;
			}
		}
	}
	return 0;
}
 
int main()
{
	int m = 0;
	int n = 0;
	int count = 0;
	char arr[ROWS][COLS];
	init(arr);
	print(arr);
	while (1)
	{
		if (count==0)
		{
			player(arr);
			count++;
		}
		else
		{
			computer(arr);
			count--;
		}
		if (full(arr) == 0)
		{
			printf("��������\n");
			if (judge(arr) == 1)
			{
				printf("���Ӯ��\n");
				break;
			}
			else if (judge(arr) == -1)
			{
				printf("����Ӯ��\n");
				break;
			}
			else
			{
				printf("ƽ��\n");
				break;
			}
		}
		if (full(arr) == 1)
		{
			if (judge(arr) == 1)
			{
				printf("���Ӯ��\n");
				break;
			}
			else if (judge(arr) == -1)
			{
				printf("����Ӯ��\n");
				break;
			}
		}
	}
	system("pause");
	return 0;
}