#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int map[4][4] = { 0 };//����2048��Ϸͼ
int cnt = 0;

//��ӡ���map
void printMap(void)
{
	printf("------------------\n");
	for (int i = 0; i < 4; i++)
	{
		printf("|");
		for (int j = 0; j < 4; j++)
		{
			
			printf("%3d", map[i][j]);
			printf("|");
		}
		printf("\n------------------\n");
	}
}

//���ڳ�ʼ���ʼ��map
void initMap(void)
{
	int firstNum_i , firstNum_j, secondNum_i, secondNum_j;
	//����������ʼ����
	//��һ������
	firstNum_i = rand() % 4;//������ֵ��СΪ0 ~ 3
	firstNum_j = rand() % 4;
	//�ڶ�������
	secondNum_i = rand() % 4;//������ֵ��СΪ0 ~ 3
	secondNum_j = rand() % 4;

	//�������������ͬ���ڶ���������������
	while (firstNum_i == secondNum_i && firstNum_j == secondNum_j)
	{
		secondNum_i = rand() % 4;//������ֵ��СΪ0 ~ 3
		secondNum_j = rand() % 4;
	}

	map[firstNum_i][firstNum_j] = 2;
	map[secondNum_i][secondNum_j] = 2;
	cnt = 2;

}
//�����µ����λ��
void createNum(void)
{
	int i, j;

	i = rand() % 4;
	j = rand() % 4;

	while (map[i][j])
	{
		i = rand() % 4;
		j = rand() % 4;
	}
	map[i][j] = 2;


}


//�����ƶ�
void up(void)
{
	int cnt_last = 0;
	
	
	//���չ����ƶ�ÿ������
	for(int i = 0;i<4;i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] != 0)//�ҵ�һ����Ϊ�������
			{
				//�����ƶ�����
				for (int k = i; k > 0; k--)
				{
					
					if (map[k - 1][j] != 0)//�ж���������������ڵ�����ֵ�Ƿ����
						break;
					map[k-1][j] = map[k][j];
					map[k][j] = 0;
				}
				
			}
		}
	//�ϲ���ͬ������
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] && map[i][j] == map[i + 1][j])
			{
				map[i][j] *= 2;
				map[i+1][j] = 0;
				cnt--;
			}

		}
	//���չ����ƶ�ÿ������
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] != 0)//�ҵ�һ����Ϊ�������
			{
				//�����ƶ�����
				for (int k = i; k > 0; k--)
				{

					if (map[k - 1][j] != 0)//�ж���������������ڵ�����ֵ�Ƿ����
						break;
					map[k - 1][j] = map[k][j];
					map[k][j] = 0;
				}

			}
		}
	if (cnt != 16)
	{
		createNum();
		cnt++;
	}

}
//�����ƶ�
void down(void)
{
	for (int i = 3; i >= 0; i--)
		for (int j = 3; j >= 0; j--)
		{
			if (map[i][j] != 0)//�ҵ�һ����Ϊ�������
			{
				//�����ƶ�����
				for (int k = i; k < 3; k++)
				{

					if (map[k + 1][j] != 0)//�ж���������������ڵ�����ֵ�Ƿ����
						break;
					map[k + 1][j] = map[k][j];
					map[k][j] = 0;
				}

			}
		}
	//�ϲ���ͬ������
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] && map[i][j] == map[i + 1][j])
			{
				map[i][j] *= 2;
				map[i+1][j] = 0;
				cnt--;
			}

		}

	for (int i = 3; i >= 0; i--)
		for (int j = 3; j >= 0; j--)
		{
			if (map[i][j] != 0)//�ҵ�һ����Ϊ�������
			{
				//�����ƶ�����
				for (int k = i; k < 3; k++)
				{

					if (map[k + 1][j] != 0)//�ж���������������ڵ�����ֵ�Ƿ����
						break;
					map[k + 1][j] = map[k][j];
					map[k][j] = 0;
				}

			}
		}
	if (cnt != 16)
	{
		createNum();
		cnt++;
	}
}
//�����ƶ�
void left(void)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] != 0)//�ҵ�һ����Ϊ�������
			{
				//�����ƶ�����
				for (int k = j; k > 0 ;k--)
				{

					if (map[i][k-1] != 0)//�ж���������������ڵ�����ֵ�Ƿ����
						break;
					map[i][k - 1] = map[i][k];
					map[i][k] = 0;
				}

			}
		}
	//�ϲ���ͬ����
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] && map[i][j] == map[i ][j+1])
			{
				map[i][j] *= 2;
				map[i][j + 1] = 0;
				cnt--;
			}

		}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] != 0)//�ҵ�һ����Ϊ�������
			{
				//�����ƶ�����
				for (int k = j; k > 0; k--)
				{

					if (map[i][k - 1] != 0)//�ж���������������ڵ�����ֵ�Ƿ����
						break;
					map[i][k - 1] = map[i][k];
					map[i][k] = 0;
				}

			}
		}
	if (cnt != 16)
	{
		createNum();
		cnt++;
	}
}
//�����ƶ�
void right(void)
{
	for (int i = 3; i >= 0; i--)
		for (int j = 3; j >= 0; j--)
		{
			if (map[i][j] != 0)//�ҵ�һ����Ϊ�������
			{
				//�����ƶ�����
				for (int k = j; k < 3; k++)
				{

					if (map[i][k + 1] != 0)//�ж���������������ڵ�����ֵ�Ƿ����
						break;
					map[i][k + 1] = map[i][k];
					map[i][k] = 0;
				}

			}
		}
	//�ϲ���ͬ����
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] && map[i][j] == map[i][j + 1])
			{
				map[i][j] *= 2;
				map[i][j + 1] = 0;
				cnt--;
			}

		}

	for (int i = 3; i >= 0; i--)
		for (int j = 3; j >= 0; j--)
		{
			if (map[i][j] != 0)//�ҵ�һ����Ϊ�������
			{
				//�����ƶ�����
				for (int k = j; k < 3; k++)
				{

					if (map[i][k + 1] != 0)//�ж���������������ڵ�����ֵ�Ƿ����
						break;
					map[i][k + 1] = map[i][k];
					map[i][k] = 0;
				}

			}
		}
	if (cnt != 16)
	{
		createNum();
		cnt++;
	}

}
//trueΪ��Ϸ����
//false��Ϸδ����
bool isOver(void)
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (map[i][j] == map[i][j + 1])return false;
			if (map[i][j] == map[i + 1][j])return false;

		}
	return true;
}
void move(char key)
{
	switch (key)
	{	
	case 'w':
	case 'W':up(); break;
	case 's':
	case 'S':down(); break;
	case 'a':
	case 'A':left(); break;
	case 'd':
	case 'D':right(); break;
	case 'q':
	case 'Q':exit(0);
	default:
		break;
	}
}

int main(int argc, char *argv[])
{
	srand((unsigned int)time(NULL));
	char key = 0;
	initMap();
	while (1)
	{
		printMap();
		if (_kbhit)
		{
			key = _getch();
			
			system("cls");
		}
		if (true == isOver())
			break;
		move(key);
		cout << "key = " << key << endl;
		
		
	}
	cout << "��Ϸ����" << endl;
	
	return 0;
	
}