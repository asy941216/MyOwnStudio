#pragma once
#define MAX 100
#define NUM 10

struct Array {
	int AllNum[MAX] = { 0, }; //�� ������ MAX����ŭ �Էµ� ������ ����
	int CountNum[NUM] = { 0, }; //�迭�� ��ȣ => (��ȣ+1)�� ����
	int* SaveAddr[NUM]; //Count�� �ּҸ� �����ϴ� ����
	int* MaxAddr = 0; //���� ū ������ �ּҸ� SaveAddr���� �޾� �����ϴ� ����
	int* SameAddr = 0; //���� ū ���� 2���� ������ ǥ��.
};