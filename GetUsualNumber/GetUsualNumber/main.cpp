#include <iostream>
#include <stdlib.h>
#include "Array.h"
using namespace std;

void Count(int* a, int* b);
void Print(int* a, int num);
void FindMax(int* a, int** b, int** m);
void Result(int t, int* s);

int main()
{
	Array arr;
	
	// 1 ~ (NUM - 1)�� ���ڰ� ���� MAX�� ����ִ� �迭 AllNum ����
	for (int i = 0; i < MAX; i++)
		arr.AllNum[i] = rand() % NUM + 1;

	/* AllNum���� ������ ������ ���� ���� CountNum�� ����
	(Count = {(1�� ����), (2�� ����), ... ((NUM - 1)�� ����)}) */
	Count(arr.AllNum, arr.CountNum);

	for (int a = 0; a < NUM; a++)
		arr.CopyNum[a] = arr.CountNum[a];

	// ��� ���ڿ� �� ���ڵ� ������ ������ ���
	Print(arr.AllNum, MAX);
	Print(arr.CountNum, NUM);

	// CountNum�� �ּҸ� SaveAddr�� ����
	for (int j = 0; j < NUM; j++)
		arr.SaveAddr[j] = arr.CountNum + j;

	FindMax(arr.CountNum, arr.SaveAddr, &arr.MaxAddr);

	//�ִ� ������ ���� ���� �� �ֺ��� ���� �Ǵ�
	for (int k = 0; k < NUM; k++)
		if (arr.CopyNum[k] == *arr.MaxAddr)
		{
			arr.SameAddr[k] = 1;
			arr.temp++;
		}

	//��� ���
	Result(arr.temp, arr.SameAddr);
	
	return 0;
}