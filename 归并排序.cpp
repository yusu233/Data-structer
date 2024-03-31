#include<iostream>
using namespace std;
#define MAXSIZE 100

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
void swap(SqList* L, int i, int j) {
	int temp = L->data[i];
	L->data[i] = L->data[j];
	L->data[j] = temp;
}

//�鲢����
//���������������顢��ʱ���顢�����㡢�Ұ���㡢�����յ�
void Merge(int A[], int TempA[], int L, int R, int RightEnd) {
	int LeftEnd = R - 1;
	int temp = L;
	int Length = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd){
		if (A[L] <= A[R])
			TempA[temp++] = A[L++];
		else
			TempA[temp++] = A[R++];
	}
	while (L <= LeftEnd)
		TempA[temp++] = A[L++];
	while (R <= RightEnd)
		TempA[temp++] = A[R++];
	//����ʱ�����ֵ���Ƶ����������
	for (int i = 0; i < Length; i++, RightEnd--)
		A[RightEnd] = TempA[RightEnd];
}

//�ݹ���ʽ�Ĺ鲢����
void Msort(int A[], int TempA[], int L, int RightEnd) {
	int Center;
	if (L < RightEnd){
		Center = (L + RightEnd) / 2;
		Msort(A, TempA, L, Center);
		Msort(A, TempA, Center + 1, RightEnd);
		Merge(A, TempA, L, Center + 1, RightEnd);
	}
}

void MergeSort(SqList* L) {
	int* TempA = new int[MAXSIZE];
	if (TempA){
		Msort(L->data, TempA, 1, L->length);
			delete[] TempA;
	}
	else
		cout << "�ռ䲻�㣡 ";
}


//�ǵݹ���ʽ�Ĺ鲢����(NΪ����Ԫ�صĸ�����lengthΪ��ǰ�������еĳ��ȣ�
//���������������顢��ʱ���顢�����㡢�Ұ���㡢�����յ�
void Merge1(int A[], int TempA[], int L, int R, int RightEnd) {
	int LeftEnd = R - 1;
	int temp = L;
	int Length = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd) {
		if (A[L] <= A[R])
			TempA[temp++] = A[L++];
		else
			TempA[temp++] = A[R++];
	}
	while (L <= LeftEnd)
		TempA[temp++] = A[L++];
	while (R <= RightEnd)
		TempA[temp++] = A[R++];
}  //����ڵݹ���ʽ��merge����������������Ĳ��ַŵ���MergeSort������

void MergePass(int A[], int TempA[], int N, int length) {
	int i;
	for (i = 1;  i <= N - 2 * length;  i += 2 * length)
		Merge1(A, TempA, i, i + length, i + 2 * length - 1);
	//�鲢���ʣ��һ���������к�һ������������
	if (i + length <= N)
		Merge1(A, TempA, i, i + length, N);
	else
		for (int j = i; j <= N; j++)
			TempA[j] = A[j];
}

void MergeSort1(SqList* L) {
	int length = 1;  //��ʼ�������г���
	int* TempA = new int[MAXSIZE];
	if (TempA) {
		while (length < L->length){
			//Ϊ�˱�֤����������������data�����У������Ʋ����ɶԽ���
			MergePass(L->data, TempA, L->length, length);
			length *= 2;
			MergePass(TempA, L->data, L->length, length);
			length *= 2;
		}
		delete[] TempA;
	}
	else
		cout << "�ռ䲻�㣡 ";
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

	MergeSort1(&L);
	print(L);

	return 0;
}