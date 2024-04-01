#include<iostream>
using namespace std;
#define MAXSIZE 100
#define CUTOFF 7  //����ʹ�ÿ��Ż��ǲ����������ֵ

struct SqList {
	int data[MAXSIZE + 1];
	int length;
};

//�ṹ���ʼ������
void initSqList(SqList* L) {
	for (int i = 0; i <= MAXSIZE; i++)
		L->data[i] = 0;
	L->length = 0;
}

//����Ԫ�أ����±�1��ʼ�洢���ݣ�
void insert(SqList* L, int data) {
	L->data[1 + L->length++] = data;
}

//��ӡ����
void print(SqList L) {
	for (int i = 1; i <= L.length; i++)
		cout << L.data[i] << endl;
}

//����Ԫ��
void swap(int* L, int i, int j) {
	int temp = L[i];
	L[i] = L[j];
	L[j] = temp;
}

//ֱ�Ӳ��������㷨
void InsertSort(int* L, int Left, int Right) {
	int j;
	for (int i = Left + 1; i <= Right; i++) {
		if (L[i] < L[i - 1]) {
			int temp = L[i];
			for (j = i - 1; L[j] > temp; j--)
				L[j + 1] = L[j];
			L[j + 1] = temp;
		}
	}
}

//��Ԫѡȡ
int Median3(int A[], int Left, int Right) {
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		swap(A, Left, Center);
	if (A[Left] > A[Right])
		swap(A, Left, Right);
	if (A[Center] > A[Right])
		swap(A, Center, Right);
	//A[Left] <= A[Center] <= A[Right]
	swap(A, Center, Right - 1);
	//��pivot�ص��ұߣ�ֻ��Ҫ����A[Left + 1]---A[Right - 2]
	return A[Right - 1];
}

//����
void QuickSort(int A[], int Left, int Right) {
	if (Right - Left >= CUTOFF) {
		int Pivot = Median3(A, Left, Right);
		int i = Left, j = Right - 1;
		for (; ; ) {
			while (A[++i] < Pivot) {}
			while (A[--j] > Pivot) {}
			//�������е�Ԫ��ֵ����pivotʱ����Ȼ����������֤�����Ԫλ�ڼ��ϵ��м�λ��
			if (i < j)
				swap(A, i, j);
			else
				break;
		}
		swap(A, i, Right - 1);
		QuickSort(A, Left, i - 1);
		QuickSort(A, i + 1, Right);
	}
	else
		InsertSort(A, Left, Right);
}

void Quick(SqList* L) {
	QuickSort(L->data, 1, L->length);
}

int main() {
	SqList L;
	initSqList(&L);
	insert(&L, 12);
	insert(&L, 9);
	insert(&L, 1);
	insert(&L, 10);
	insert(&L, 5);
	insert(&L, 8);
	insert(&L, 11);
	insert(&L, 3);
	insert(&L, 7);
	insert(&L, 13);
	insert(&L, 4);
	insert(&L, 6);
	insert(&L, 14);
	insert(&L, 2);

	print(L);
	cout << endl;

	Quick(&L);
	print(L);

	return 0;
}