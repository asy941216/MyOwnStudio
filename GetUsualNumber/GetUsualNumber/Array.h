#pragma once
#define MAX 100
#define NUM 9

struct Array {
	int AllNum[MAX] = { 0, }; //�� ������ MAX����ŭ �Էµ� ������ ����
	int CountNum[NUM] = { 0, }; //�迭�� ��ȣ => (��ȣ+1)�� ����
	int CopyNum[NUM] = { 0, };
	int* SaveAddr[NUM]; //Count�� �ּҸ� �����ϴ� ����
	int* MaxAddr = 0; //���� ū ������ �ּҸ� SaveAddr���� �޾� �����ϴ� ����
	int SameAddr[NUM] = { 0, }; //���� ū ���� ����ִ� ������ ǥ��.
	int temp = 0; //�ֺ��� ������ �Ǵ�. temp == NUM �̸� ��� �����Ƿ� �ֺ��� ����.
};