#include <iostream>
#include <stdlib.h>
using namespace std;

void Count(int* a, int* b, int num1, int num2) //a�� �� ������ ������ ���� b�� �����ϴ� ��
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
//a���� ���� ū ���ڸ� ��� m�� �ִ� ��, s�� ���� ū ���� �ߺ����� �ִ��� �Ǵ�
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