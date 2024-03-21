#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef char TElemType;
TElemType null = ' ';
int treeIndex = 1;
typedef char String[24]; /*  0�ŵ�Ԫ��Ŵ��ĳ��� */
String str;

//���������ṹ
struct BTNode {
	TElemType data;
	BTNode* lchild, *rchild;
};

//�����ն�����
bool InitBTree(BTNode** T) {
	T = NULL;
	return true;
}


//�ж϶������Ƿ�Ϊ��
bool BTreeEmpty(BTNode* T) {
	if (T->data == ' ')
	{
		return true;
	}
	return false;
}

//���������
int BTreeDepth(BTNode* T) {
	int leftdepth, rightdepth;
	if (BTreeEmpty(T))
		return 0;
	if (T->lchild)
		leftdepth = BTreeDepth(T->lchild);
	else
		leftdepth = 0;
	if (T->rchild)
		rightdepth = BTreeDepth(T->rchild);
	else
		rightdepth = 0;
	return leftdepth > rightdepth ? leftdepth : rightdepth;
}

//���ض������ĸ��ڵ�
TElemType BTreeRoot(BTNode* T) {
	if (BTreeEmpty(T))
		return ' ';
	else
		return T->data;
}

//����ָ������ֵ
TElemType Value(BTNode* position) {
	return position->data;
}

//Ϊָ����㸳ֵ
void BTreeAssign(BTNode* position, TElemType value) {
	position->data = value;
}

//ǰ�����������
void PreOrderTraverse(BTNode* T) {
	if (T == NULL)
		return;
	cout << T->data << endl;
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//�������������
void InOrderTraverse(BTNode* T) {
	if (T == NULL)
	{
		return;
	}
	InOrderTraverse(T->lchild);
	cout << T->data << endl;
	InOrderTraverse(T->rchild);
}

//�������������
void PostOrderTraverse(BTNode* T) {
	if (T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	cout << T->data << endl;
}

bool StrAssign(String T, const char* chars)
{
	int i;
	if (strlen(chars) > MAXSIZE)
		return false;
	else
	{
		T[0] = strlen(chars);
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return true;
	}
}

void CreateBiTree(BTNode* &T)
{
	TElemType ch;

	/* scanf("%c",&ch); */
	ch = str[treeIndex++];

	if (ch == '#')
		T = NULL;
	else
	{
		T = new BTNode;
		if (!T)
			exit(OVERFLOW);
		T->data = ch; /* ���ɸ���� */
		CreateBiTree(T->lchild); /* ���������� */
		CreateBiTree(T->rchild); /* ���������� */
	}
}

int main()
{
	BTNode* T;
	TElemType e1;
	InitBTree(&T);
	StrAssign(str, "ABDH#K###E##CFI###G#J##");

	CreateBiTree(T);

	printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n", BTreeEmpty(T), BTreeDepth(T));
	e1 = BTreeRoot(T);
	printf("�������ĸ�Ϊ: %c\n", e1);

	printf("\nǰ�����������:");
	PreOrderTraverse(T);
	printf("\n�������������:");
	InOrderTraverse(T);
	printf("\n�������������:");
	PostOrderTraverse(T);
	return 0;
}