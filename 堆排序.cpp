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
void insert(SqList* L, int data) {
	L->data[1 + L->length++] = data;
}

//��ӡ����
void print(SqList L) {
	for (int i = 1; i <= L.length; i++)
		cout << L.data[i] << endl;
}

//����Ԫ��
void swap(SqList* L, int i, int j) {
	int temp = L->data[i];
	L->data[i] = L->data[j];
	L->data[j] = temp;
}

//��������
void HeapAdjust(SqList* L, int s, int length) {
	int temp = L->data[s];
	for (int child = 2 * s; child <= length; child *= 2){
		//Ѱ�����Һ����нϴ��һ��
		if (child < length && L->data[child] < L->data[child + 1])
			child++;
		if (temp >= L->data[child])
			break;
		L->data[s] = L->data[child];
		s = child;
	}
	L->data[s] = temp;
}

//������
void HeapSort(SqList* L) {
	//����ǰ�ȹ�������
	//���������鹹�����ѷ������������ϡ��������󣬽�ÿ����Ҷ�ڵ㵱�����ڵ㣬���������������������
	for (int i = L->length / 2; i > 0; i--)
		HeapAdjust(L, i, L->length);

	//��������
	for (int j = L->length; j > 0; j--){
		swap(L, 1, j);
		HeapAdjust(L, 1, j - 1);
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
	cout << endl;
	HeapSort(&L);
	print(L);

	return 0;
}