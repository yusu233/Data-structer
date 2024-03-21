#include<iostream>
using namespace std;

typedef int SElemtype;
#define MAXSIZE 20

struct StackNode {
	SElemtype data;
	StackNode* next;
	StackNode(SElemtype x) : data(x), next(nullptr){}
};

struct LinkStack {
	StackNode* top;
	int count;
};

//������ջ
bool InitStack(LinkStack* s) {
	s->top = new StackNode(0);
	s->top = nullptr;
	s->count = 0;
	return true;
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(LinkStack s) {
	if (s.count == 0)
	{
		return true;
	}
	return false;
}

//����ջ�ĳ���
int StackLength(LinkStack s) {
	return s.count;
}

//����ջ��Ԫ��

bool GetTop(LinkStack s, SElemtype* e) {
	if (s.top == nullptr)
	{
		return false;
	}
	*e = s.top->data;
	return true;
}

//��ջ
bool Push(LinkStack* s, SElemtype e) {
	StackNode* n = new StackNode(e);
	n->next = s->top;
	s->top = n;
	s->count++;
	return true;
}

//��ջ
bool Pop(LinkStack* s, SElemtype* e) {
	if (StackEmpty(*s))
	{
		return false;
	}
	StackNode* n = s->top;
	*e = s->top->data;
	s->top = n->next;
	delete n;
	s->count--;
	return true;
}

int main()
{
	int j;
	LinkStack s;
	int e;
	if (InitStack(&s))
		for (j = 1; j <= 10; j++)
			Push(&s, j);
	Pop(&s, &e);
	printf("������ջ��Ԫ�� e=%d\n", e);
	printf("ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));
	GetTop(s, &e);
	printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n", e, StackLength(s));
	return 0;
}