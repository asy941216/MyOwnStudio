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
	
	// 1 ~ (NUM - 1)의 숫자가 총합 MAX개 들어있는 배열 AllNum 생성
	/*for (int i = 0; i < MAX; i++)
		arr.AllNum[i] = rand() % NUM + 1;*/

	arr.AllNum[0] = 5;
	arr.AllNum[1] = 1;

	/* AllNum안의 숫자의 갯수를 세어 각각 CountNum에 저장
	(Count = {(1의 갯수), (2의 갯수), ... ((NUM - 1)의 갯수)}) */
	Count(arr.AllNum, arr.CountNum, NUM, MAX);

	// 모든 숫자와 그 숫자들 각각의 갯수를 출력
	Print(arr.AllNum, MAX);
	Print(arr.CountNum, NUM);

	// CountNum의 주소를 SaveAddr에 저장
	for (int l = 0; l < NUM; l++)
		arr.SaveAddr[l] = arr.CountNum + l;

	FindMax(arr.CountNum, arr.SaveAddr, &arr.MaxAddr, &arr.SameAddr, NUM);

	//결과 출력
	if (arr.SameAddr > arr.MaxAddr)
		cout << "최빈값이 존재하지 않습니다." << endl;

	else
		cout << "최빈값은 " << (arr.MaxAddr - arr.SaveAddr[0] + 1) << endl;
	
	return 0;
}