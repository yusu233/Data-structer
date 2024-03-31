#include<iostream>

#define HASHSIZE 12

//�����ϣ��ṹ
struct HashTable{
	int* elem;
	int count;
};

int m = 0;  //�洢��ϣ��ĳ���

//��ʼ����ϣ��
void initHashTable(HashTable* H) {
	m = HASHSIZE;
	H->count = 0;
	H->elem = new int[m];
	for (int i = 0; i < m; i++){
		H->elem[i] = -1;
	}
}

//ɢ�к���
int Hash(int key) {
	//����ȡ�෨
	return key % m;
}

//����
void insertHashTable(HashTable* H, int key) {
	if (H->count <= HASHSIZE){
		int addr = Hash(key);
	    while (H->elem[addr] != -1)
		    addr = (addr + 1) % m;
	    H->elem[addr] = key;
	    H->count++;
	}
	else
		std::cout << "Hashtable is full!" << std::endl;
	
}

//��ѯ
bool searchHashTable(HashTable H, int key, int* address) {
	*address = Hash(key);
	while (H.elem[*address] != key){
		*address = (*address + 1) % m;
		if (H.elem[*address] == -1 || *address == Hash(key))
			return false;
	}
	return true;
}

int main()
{
	int arr[HASHSIZE] = { 12,67,56,16,25,37,22,29,15,47,48,34 };
	int i, p, key, result;
	HashTable H;

	key = 39;

	initHashTable(&H);
	for (i = 0; i < m; i++)
		insertHashTable(&H, arr[i]);

	result = searchHashTable(H, key, &p);
	if (result)
		printf("���� %d �ĵ�ַΪ��%d \n", key, p);
	else
		printf("���� %d ʧ�ܡ�\n", key);

	for (i = 0; i < m; i++)
	{
		key = arr[i];
		searchHashTable(H, key, &p);
		printf("���� %d �ĵ�ַΪ��%d \n", key, p);
	}

	return 0;
}