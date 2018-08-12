#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAX 100
#define NUM 10

struct Array {
	int AllNum[MAX] = { 0, }; //총 갯수가 MAX개만큼 입력된 랜덤한 숫자
	int CountNum[NUM] = { 0, }; //배열의 번호 => (번호+1)의 갯수
	int* SaveAddr[NUM]; //Count의 주소를 저장하는 공간
	int* MaxAddr = 0; //가장 큰 갯수의 주소를 SaveAddr에서 받아 저장하는 공간
	int* SameAddr = 0; //
};

int main()
{
	// 1~9의 숫자가 들어있는 배열
	int Number[MAX] = { 0, };

	for (int i = 0; i < MAX; i++)
	{
		Number[i] = rand() % NUM + 1;
	}

	//숫자의 갯수를 넣을 배열
	int Count[NUM] = { 0, };

	//각 숫자의 갯수를 세는 식
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

	//갯수가 제일 많은 숫자를 골라내는 식
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

	//결과 출력
	if (SameAddress > MaxAddress)
	{
		cout << "최빈값이 존재하지 않습니다." << endl;
	}
	else
	{
		cout << "최빈값은 " << (MaxAddress - AddrStorge[0] + 1) << endl;
	}
	return 0;
}