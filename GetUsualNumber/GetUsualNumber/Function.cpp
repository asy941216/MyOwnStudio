#include <iostream>
#include <stdlib.h>
using namespace std;

void Count(int* a, int* b, int num1, int num2) //a의 각 숫자의 갯수를 세서 b에 저장하는 식
{
	for (int j = 1; j < num1 + 1; j++)
		for (int k = 0; k < num2; k++)
			if (a[k - 1] == j)
				b[j - 1]++;
}

void Print(int* a, int num)
{
	for (int i = 0; i < num; i++)
		cout << a[i] << " ";

	cout << endl << endl;
}

void FindMax(int* a, int** b, int** m, int** s, int num)
//a에서 가장 큰 숫자를 골라 m에 넣는 식, s는 가장 큰 값이 중복으로 있는지 판단
{
	for (int i = 0; i < num - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			a[i + 1] = a[i];
			b[i + 1] = b[i];
			*m = b[i];
		}

		else if (a[i] == a[i + 1])
		{
			*s = b[i];
			i++;
		}
	}

	if (a[num - 2] < a[num - 1])
		*m = b[num - 1];
}