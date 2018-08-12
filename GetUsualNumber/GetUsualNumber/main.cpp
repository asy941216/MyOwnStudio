#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX 100
#define NUM 10

struct Array {
	int AllNum[MAX] = { 0, }; //�� ������ MAX����ŭ �Էµ� ������ ����
	int CountNum[NUM] = { 0, }; //�迭�� ��ȣ => (��ȣ+1)�� ����
	int* SaveAddr[NUM]; //Count�� �ּҸ� �����ϴ� ����
	int* MaxAddr = 0; //���� ū ������ �ּҸ� SaveAddr���� �޾� �����ϴ� ����
	int* SameAddr = 0; //
};

int main()
{
	// 1~9�� ���ڰ� ����ִ� �迭
	int Number[MAX] = { 0, };

	for (int i = 0; i < MAX; i++)
	{
		Number[i] = rand() % NUM + 1;
	}

	//������ ������ ���� �迭
	int Count[NUM] = { 0, };

	//�� ������ ������ ���� ��
	for (int j = 1; j < NUM + 1; j++)
	{
		for (int k = 0; k < MAX; k++)
		{
			if (Number[k - 1] == j)
			{
				Count[j - 1]++;
			}
		}
	}

	for (int a = 0; a < MAX; a++)
		cout << Number[a] << " ";

	cout << endl;

	for (int b = 0; b < NUM; b++)
		cout << Count[b] << endl;

	//������ ���� ���� ���ڸ� ��󳻴� ��
	int* AddrStorge[NUM];
	for (int l = 0; l < NUM; l++)
	{
		AddrStorge[l] = Count + l;
	}

	int* MaxAddress;
	int* SameAddress = 0;

	for (int m = 0; m < NUM - 1; m++)
	{
		if (Count[m] > Count[m + 1])
		{
			Count[m + 1] = Count[m];
			AddrStorge[m + 1] = AddrStorge[m];
			MaxAddress = AddrStorge[m];
		}

		else if (Count[m] == Count[m + 1])
		{
			SameAddress = AddrStorge[m];
		}
	}

	if (Count[NUM - 2] < Count[NUM - 1])
		MaxAddress = AddrStorge[NUM - 1];

	//��� ���
	if (SameAddress > MaxAddress)
	{
		cout << "�ֺ��� �������� �ʽ��ϴ�." << endl;
	}
	else
	{
		cout << "�ֺ��� " << (MaxAddress - AddrStorge[0] + 1) << endl;
	}
	return 0;
}