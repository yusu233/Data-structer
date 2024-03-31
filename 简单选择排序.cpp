#include<iostream>
using namespace std;
#define MAXSIZE 10000

struct SqList {
	int data[MAXSIZE + 1];
	int length;
};

//�ṹ���ʼ������
void initSqList(SqList* L) {
	for (int i = 1; i <= MAXSIZE; i++)
		L->data[i] = 0;
	L->length = 0;
}

//����Ԫ��
void swap(SqList* L, int i, int j) {
	int temp = L->data[i];
	L->data[i] = L->data[j];
	L->data[j] = temp;
}

//����Ԫ��
void insert(SqList* L, int data) {
	L->data[1 + L->length++] = data;
}

//��ӡ����
void print(SqList L) {
	for (int i = 1; i <= L.length; i++)
		cout << L.data[i] << endl;
}

//��ѡ������
void SelectSort(SqList* L) {
	for (int i = 1; i < L->length; i++){
		int min = i;
		for (int j = i + 1; j <= L->length; j++){
			if (L->data[j] < L->data[min])
				min = j;
		}
		if (min != i)
			swap(L, i, min);
	}
}

int main() {
	SqList L;
	initSqList(&L);
	insert(&L, 9);
	insert(&L, 1);
	insert(&L, 5);
	insert(&L, 8);
	insert(&L, 3);
	insert(&L, 7);
	insert(&L, 4);
	insert(&L, 6);
	insert(&L, 2);
	print(L);

	SelectSort(&L);
	print(L);

	return 0;
}