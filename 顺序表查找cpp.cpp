#include<iostream>
using namespace std;

//�򵥵�˳������
int Sequential_Search(int* a, int n, int key) {
	//Ϊ����ڶ��ֲ��ҷ�ʽ�±�ͳһ��������±�1��ʼ�洢
	for (int i = 1; i <= n; i++){
		if (a[i] == key)
			return i;
	}
	return 0;
}

//ʹ���ڱ��ڵ��˳������
int Sequential_Search2(int* a, int n, int key) {
	a[0] = key;
	int i = n;
	while (a[i] != key)
		i--;
	return i;
}

