#include<iostream>
using namespace std;

typedef int TElemtype;
#define MAXSIZE 20

//˫�ױ�ʾ��
struct PTNode
{
	TElemtype data;
	int parent;
};

struct Ptree
{
	PTNode nodes[MAXSIZE];
	int r, n;
};

//���ӱ�ʾ��
struct CNode
{
	int child; //��ʾ���ӽ���������д洢��λ��
	CNode* next;
};

struct PTNode
{
	TElemtype data;
	CNode* firstchild;
};

struct Tree
{
	PTNode nodes[MAXSIZE];
	int r, n;
};

//�����ֵܱ�ʾ��
struct CSNode
{
	TElemtype data;
	CNode* firstchild;
	CNode* rightsib;
};