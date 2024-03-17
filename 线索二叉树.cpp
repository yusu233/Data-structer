#include<iostream>
using namespace std;

typedef char ElemType;
typedef enum{Link, Thread} Tag;

class BiThreadThree
{
public:
	BiThreadThree(): T(nullptr), H(){}
	void insert() {
		Insert(&T);
	}
	void inthread() {
		InorderThread(&H, T);
	}
	void traverse() {
		InOrderTraverse(H);
	}

private:
	//�����������������ṹ
	struct BiThrNode {
		ElemType data;
		Tag LTag, RTag;
		BiThrNode* lchild;
		BiThrNode* rchild;
	};

	//���������
	BiThrNode* T, *H;

	//��ʼ��һ�ſն�����
	BiThrNode* InitBTT() {
		BiThrNode* T = new BiThrNode;
		T->data = '#';
		T->lchild = T->rchild = nullptr;
		T->LTag = T->RTag = Link;
		return T;
	}

	//��������в���Ԫ��(ǰ��)
	void Insert(BiThrNode** T) {
		char ch;
		cout << "�����ַ���";
		cin >> ch;
		if (ch == '#')
				*T = nullptr;
		else{
			*T = new BiThrNode;
			(*T)->data = ch;
			Insert(&(*T)->lchild);
			if ((*T)->lchild)
				(*T)->LTag = Link;
			Insert(&(*T)->rchild);
			if ((*T)->rchild)
				(*T)->RTag = Link;
		}
	}

	//���������������������
	BiThrNode* pre;//�洢ǰһ�����ĵ�ַ
	void InThread(BiThrNode* p) {
		if (p){
			InThread(p->lchild);
			if (p->lchild == nullptr){
				p->LTag = Thread;
				p->lchild = pre;
			}
			//���p�ĺ�̽�㻹δ���ʣ����޸���һ�������Һ���
			if (pre->rchild == nullptr) {
				pre->RTag = Thread;
				pre->rchild = p;
			}
			pre = p;
			InThread(p->rchild);
		}
	}

	//����������������������������������ͷ�ڵ�
	void InorderThread(BiThrNode** Thr , BiThrNode* T) {
		*Thr = new BiThrNode;
		(*Thr)->LTag = Link;
		(*Thr)->RTag = Thread;
		(*Thr)->rchild = *Thr;
		if (!T)
			(*Thr)->lchild = *Thr;
		else{
			(*Thr)->lchild = T;
			pre = (*Thr);
			InThread(T);
			pre->rchild = *Thr;
			pre->RTag = Thread;
			(*Thr)->rchild = pre;
		}
	}

	//�����������������
	void InOrderTraverse(BiThrNode* T) {
		BiThrNode* p;
		p = T->lchild;
		while (p != T){
			while (p->LTag == Link)
				p = p->lchild;
			cout << p->data << endl;
			while (p->RTag == Thread && p->rchild != T){
				p = p->rchild;
				cout << p->data << endl;
			}
			p = p->rchild;
		}
	}
};


int main()
{
	BiThreadThree test;
	cout << "�밴ǰ�����������(��:'ABDH##I##EJ###CF##G##')" << endl;;
	test.insert(); /* ��ǰ����������� */
	test.inthread(); /* �������,������������������ */
	cout << "�������(���)����������: " << endl;;
	test.traverse(); /* �������(���)���������� */

	return 0;
}
