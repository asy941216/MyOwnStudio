#include <iostream>
#include <stdlib.h>
#include "Array.h"
using namespace std;

void Count(int* a, int* b, int num1, int num2);
void Print(int* a, int num);
void FindMax(int* a, int** b, int** m, int** s, int num);

int main()
{
	Array arr;
	
	// 1 ~ (NUM - 1)�� ���ڰ� ���� MAX�� ����ִ� �迭 AllNum ����
	/*for (int i = 0; i < MAX; i++)
		arr.AllNum[i] = rand() % NUM + 1;*/

	arr.AllNum[0] = 5;
	arr.AllNum[1] = 1;

	/* AllNum���� ������ ������ ���� ���� CountNum�� ����
	(Count = {(1�� ����), (2�� ����), ... ((NUM - 1)�� ����)}) */
	Count(arr.AllNum, arr.CountNum, NUM, MAX);

	// ��� ���ڿ� �� ���ڵ� ������ ������ ���
	Print(arr.AllNum, MAX);
	Print(arr.CountNum, NUM);

	// CountNum�� �ּҸ� SaveAddr�� ����
	for (int l = 0; l < NUM; l++)
		arr.SaveAddr[l] = arr.CountNum + l;

	FindMax(arr.CountNum, arr.SaveAddr, &arr.MaxAddr, &arr.SameAddr, NUM);

	//��� ���
	if (arr.SameAddr > arr.MaxAddr)
		cout << "�ֺ��� �������� �ʽ��ϴ�." << endl;

	else
		cout << "�ֺ��� " << (arr.MaxAddr - arr.SaveAddr[0] + 1) << endl;
	
	return 0;
}