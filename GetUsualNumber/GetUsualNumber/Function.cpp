#include <iostream>
#include <stdlib.h>
#include "Array.h"
using namespace std;

void Count(int* a, int* b) //a�� �� ������ ������ ���� b�� �����ϴ� ��
{
	for (int j = 1; j < NUM + 1; j++)
		for (int k = 0; k < MAX; k++)
			if (a[k - 1] == j)
				b[j - 1]++;
}

void Print(int* a, int num)
{
	for (int i = 0; i < num; i++)
		cout << a[i] << " ";

	cout << endl << endl;
}

void FindMax(int* a, int** b, int** m)
//a���� ���� ū ���ڸ� ��� m�� �ִ� ��
{
	for (int i = 0; i < NUM - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			a[i + 1] = a[i];
			b[i + 1] = b[i];
			*m = b[i];
		}

		else if (a[i] == a[i + 1])
			*m = b[i];
	}

	if (a[NUM - 2] < a[NUM - 1])
		*m = b[NUM - 1];
}

void Result(int t, int* s)
{
	if (t == NUM)
		cout << "�ֺ��� �����ϴ�." << endl;

	else
	{
		cout << "�ֺ��� ";
		for (int i = 0; i < NUM; i++)
			if (s[i] > 0)
				cout << i + 1 << " ";
		cout << endl << endl;
	}
}