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
	
	// 1 ~ (NUM - 1)의 숫자가 총합 MAX개 들어있는 배열 AllNum 생성
	for (int i = 0; i < MAX; i++)
		arr.AllNum[i] = rand() % NUM + 1;

	/* AllNum안의 숫자의 갯수를 세어 각각 CountNum에 저장
	(Count = {(1의 갯수), (2의 갯수), ... ((NUM - 1)의 갯수)}) */
	Count(arr.AllNum, arr.CountNum);

	for (int a = 0; a < NUM; a++)
		arr.CopyNum[a] = arr.CountNum[a];

	// 모든 숫자와 그 숫자들 각각의 갯수를 출력
	Print(arr.AllNum, MAX);
	Print(arr.CountNum, NUM);

	// CountNum의 주소를 SaveAddr에 저장
	for (int j = 0; j < NUM; j++)
		arr.SaveAddr[j] = arr.CountNum + j;

	FindMax(arr.CountNum, arr.SaveAddr, &arr.MaxAddr);

	//최대 갯수를 가진 숫자 및 최빈값의 유무 판단
	for (int k = 0; k < NUM; k++)
		if (arr.CopyNum[k] == *arr.MaxAddr)
		{
			arr.SameAddr[k] = 1;
			arr.temp++;
		}

	//결과 출력
	Result(arr.temp, arr.SameAddr);
	
	return 0;
}