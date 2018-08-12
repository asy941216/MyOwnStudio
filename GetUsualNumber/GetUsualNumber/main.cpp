#include <iostream>
#include <stdlib.h>
#include "Array.h"
using namespace std;

void Count(int* a, int* b, int num1, int num2);
void Print(int* a, int num);
void FindMax(int* a, int** b, int** m, int num);

int main()
{
	Array arr;
	
	// 1 ~ (NUM - 1)�� ���ڰ� ���� MAX�� ����ִ� �迭 AllNum ����
	/*for (int i = 0; i < MAX; i++)
		arr.AllNum[i] = rand() % NUM + 1;*/

	arr.AllNum[0] = 5;
	arr.AllNum[1] = 1;
	arr.AllNum[2] = 1;
	arr.AllNum[3] = 5;
	arr.AllNum[4] = 3;

	/* AllNum���� ������ ������ ���� ���� CountNum�� ����
	(Count = {(1�� ����), (2�� ����), ... ((NUM - 1)�� ����)}) */
	Count(arr.AllNum, arr.CountNum, NUM, MAX);

	for (int a = 0; a < NUM; a++)
		arr.CopyNum[a] = arr.CountNum[a];

	// ��� ���ڿ� �� ���ڵ� ������ ������ ���
	Print(arr.AllNum, MAX);
	Print(arr.CountNum, NUM);

	// CountNum�� �ּҸ� SaveAddr�� ����
	for (int j = 0; j < NUM; j++)
		arr.SaveAddr[j] = arr.CountNum + j;

	FindMax(arr.CountNum, arr.SaveAddr, &arr.MaxAddr, NUM);

	//��� ���
	int temp = 0;
	for (int k = 0; k < NUM; k++)
	{
		if (arr.CopyNum[k] == *arr.MaxAddr)
		{
			arr.SameAddr[k] = 1;
			temp++;
		}
	}

	if (temp > 0)
	{
		cout << "�ֺ��� ";
		for (int l = 0; l < NUM; l++)
		{
			if (arr.SameAddr[l] > 0)
				cout << (arr.SameAddr + l - arr.SameAddr + 1) << " ";
		}
		cout << endl << endl;
	}

	else
		cout << "�ֺ��� �����ϴ�." << endl;
	
	return 0;
}