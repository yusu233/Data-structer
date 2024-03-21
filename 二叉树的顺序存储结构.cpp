#include<iostream>
using namespace std;

#define MAXSIZE 100
#define MAX_TREE_SIZE 100

typedef  int TElemtype;
typedef TElemtype SqBiTree[MAX_TREE_SIZE];

//��ʼ��������
bool InitBiTree(SqBiTree T) {
	for (int i = 0; i < MAX_TREE_SIZE; i++)
	{
		T[i] = 0;
	}
	return true;
}

bool CreateBiTree(SqBiTree T)
{
	int i = 0;
	printf("�밴�����������ֵ(����)��0��ʾ�ս�㣬��999�������������%d:\n", MAX_TREE_SIZE);
	while (i < 10)
	{
		T[i] = i + 1;

		if (i != 0 && T[(i + 1) / 2 - 1] == -1 && T[i] != -1) /* �˽��(����)��˫���Ҳ��Ǹ� */
		{
			printf("������˫�׵ķǸ����%d\n", T[i]);
			exit(0);
		}
		i++;
	}
	while (i < MAX_TREE_SIZE)
	{
		T[i] = -1; /* ���ո�ֵ��T�ĺ���Ľ�� */
		i++;
	}

	return true;
}

//�ж϶������Ƿ�Ϊ��
bool BiEmpty(SqBiTree T) {
	if (T[0] == -1)
	{
		return true;
	}
	return false;
}

//���������
int BiTreeDepth(SqBiTree T) {
	int i, j = -1;
	for (i = MAX_TREE_SIZE - 1; i >=0; i--)
	{
		if (T[i] != -1) {
			break;
		}
	}
	i++;
	while (i >= powl(2, j))
	{
		j++;
	}
	return j;
}

//���ض��������ڵ��ֵ
bool BiTreeRoot(SqBiTree T, TElemtype* e) {
	if (BiEmpty(T))
	{
		return false;
	}
	*e = T[0];
	return true;
}

//����ָ��λ�õ�ֵ
struct Pos
{
	int level, order;
};//λ�õĸ�ʽ

TElemtype BiTreeValue(SqBiTree T, Pos e) {
	return T[(int)powl(2, e.level - 1) + e.order -2];//��ȥ2����Ϊ����±��0��ʼ���ұ��ʽ��һ���Ѿ�����˱����һ�����λ�ã���order�е��ظ�
}

//Ϊָ��λ�õĶ�������㸳ֵ
bool BiTreeAssign(SqBiTree T, Pos e, TElemtype value) {
	int p = (int)powl(2, e.level - 1) + e.order - 2;
	if (value != -1 && T[(p + 1) / 2 - 1] == -1)
	{
		return false;
	}
	else if(value == -1 && T[p * 2 + 1] != -1 || T[p * 2 + 2] != -1)
	{
		return false;
	}
	T[p] = value;
	return true;
}

//����˫�׽��
TElemtype BiTreeParent(SqBiTree T, TElemtype e) {
	if (T[0] == -1)
	{
		return false;
	}
	for (int i = 0; i < MAX_TREE_SIZE; i++)
	{
		if (T[i] == e) {
			return T[(i + 1) / 2 - 1];
		}
	}
	return -1;
}

//����e�ĺ��ӽ��
TElemtype Leftchild(SqBiTree T, TElemtype e) {
	if (T[0] == -1)
	{
		return false;
	}
	for (int i = 0; i < MAX_TREE_SIZE; i++)
	{
		if (T[i] == e)
			return T[i * 2 + 1];//������Һ������±�Ϊ2i+2��
	}
	return false;
}

//�������ֵܽ��
TElemtype LeftSib(SqBiTree T, TElemtype e) {
	if (T[0] == -1)
	{
		return false;
	}
	for (int i = 0; i < MAX_TREE_SIZE; i++)
	{
		if (T[i] == e && i % 2 == 0)
			return T[i - 1];
	}
	return false;
}//���ֵܽ��ͬ��

//ǰ������ݹ鷽��
void PreTraverse(SqBiTree T, int index) {
	cout << T[index] << " ";
	if (T[2 * index + 1] != -1)
		PreTraverse(T, 2 * index + 1);
	if (T[2 * index + 2] != -1)
		PreTraverse(T, 2 * index + 2);
}

bool PreOrderTraverse(SqBiTree T) {
	if (!BiEmpty(T))
	{
		PreTraverse(T, 0);
	}
	return true;
}

//�������
void InTraverse(SqBiTree T, int index) {
	
	if (T[2 * index + 1] != -1)
		InTraverse(T, 2 * index + 1);
	cout << T[index] << " ";
	if (T[2 * index + 2] != -1)
		InTraverse(T, 2 * index + 2);
}

bool InOrderTraverse(SqBiTree T) {
	if (!BiEmpty(T))
	{
		InTraverse(T, 0);
	}
	return true;
}

//�������
void PostTraverse(SqBiTree T, int index) {

	if (T[2 * index + 1] != -1)
		PostTraverse(T, 2 * index + 1);
	if (T[2 * index + 2] != -1)
		PostTraverse(T, 2 * index + 2);
	cout << T[index] << " ";
}

bool PostOrderTraverse(SqBiTree T) {
	if (!BiEmpty(T))
	{
		PostTraverse(T, 0);
	}
	return true;
}


//�������
void LevelOrderTraverse(SqBiTree T) {
	int i = MAX_TREE_SIZE - 1;
	while (T[i] == -1)
		i--;
	for (int j = 0; j <= i; j++)
	{
		if (T[j] != -1)
			cout << T[j] << " ";
	}
}

int main()
{
	Pos p;
	TElemtype e;
	SqBiTree T;
	InitBiTree(T);
	CreateBiTree(T);
	printf("������������,���շ�%d(1:�� 0:��) �������=%d\n", BiEmpty(T), BiTreeDepth(T));
	bool i = BiTreeRoot(T, &e);
	if (i)
		printf("�������ĸ�Ϊ��%d\n", e);
	else
		printf("���գ��޸�\n");
	printf("�������������:\n");
	LevelOrderTraverse(T);
	printf("ǰ�����������:\n");
	PreOrderTraverse(T);
	printf("�������������:\n");
	InOrderTraverse(T);
	printf("�������������:\n");
	PostOrderTraverse(T);
	printf("�޸Ľ��Ĳ��3�������2��");
	p.level = 3;
	p.order = 2;
	e = BiTreeValue(T, p);
	printf("���޸Ľ���ԭֵΪ%d��������ֵ:50 ", e);
	e = 50;
	BiTreeAssign(T, p, e);
	printf("ǰ�����������:\n");
	PreOrderTraverse(T);
	printf("���%d��˫��Ϊ%d", e, BiTreeParent(T, e));
	printf("���� %d", Leftchild(T, e));
	printf("���ֵ� %d\n", LeftSib(T, e));
	return 0;
}