#pragma once
#define MAX 100
#define NUM 9

struct Array {
	int AllNum[MAX] = { 0, }; //총 갯수가 MAX개만큼 입력된 랜덤한 숫자
	int CountNum[NUM] = { 0, }; //배열의 번호 => (번호+1)의 갯수
	int CopyNum[NUM] = { 0, };
	int* SaveAddr[NUM]; //Count의 주소를 저장하는 공간
	int* MaxAddr = 0; //가장 큰 갯수의 주소를 SaveAddr에서 받아 저장하는 공간
	int SameAddr[NUM] = { 0, }; //가장 큰 수가 들어있는 지점을 표시.
	int temp = 0; //최빈값의 유무를 판단. temp == NUM 이면 모두 같으므로 최빈값이 없음.
};