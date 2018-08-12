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
	
	// 1 ~ (NUM - 1)의 숫자가 총합 MAX개 들어있는 배열 AllNum 생성
	/*for (int i = 0; i < MAX; i++)
		arr.AllNum[i] = rand() % NUM + 1;*/

	arr.AllNum[0] = 5;
	arr.AllNum[1] = 1;
	arr.AllNum[2] = 1;
	arr.AllNum[3] = 5;
	arr.AllNum[4] = 3;

	/* AllNum안의 숫자의 갯수를 세어 각각 CountNum에 저장
	(Count = {(1의 갯수), (2의 갯수), ... ((NUM - 1)의 갯수)}) */
	Count(arr.AllNum, arr.CountNum, NUM, MAX);

	for (int a = 0; a < NUM; a++)
		arr.CopyNum[a] = arr.CountNum[a];

	// 모든 숫자와 그 숫자들 각각의 갯수를 출력
	Print(arr.AllNum, MAX);
	Print(arr.CountNum, NUM);

	// CountNum의 주소를 SaveAddr에 저장
	for (int j = 0; j < NUM; j++)
		arr.SaveAddr[j] = arr.CountNum + j;

	FindMax(arr.CountNum, arr.SaveAddr, &arr.MaxAddr, NUM);

	//결과 출력
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
		cout << "최빈값은 ";
		for (int l = 0; l < NUM; l++)
		{
			if (arr.SameAddr[l] > 0)
				cout << (arr.SameAddr + l - arr.SameAddr + 1) << " ";
		}
		cout << endl << endl;
	}

	else
		cout << "최빈값이 없습니다." << endl;
	
	return 0;
}