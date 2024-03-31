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

//ֱ�Ӳ��������㷨
void InsertSort(SqList* L) {
	int j;
	for (int i = 2; i <= L->length; i++){
		if (L->data[i] < L->data[i - 1]) {
			L->data[0] = L->data[i];
			for (j = i - 1; L->data[j] > L->data[0]; j--)
				L->data[j + 1] = L->data[j];
			L->data[j + 1] = L->data[0];
		}
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
	InsertSort(&L);
	print(L);
	return 0;
}