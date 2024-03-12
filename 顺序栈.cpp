#include<iostream>
using namespace std;

#include<iostream>

using namespace std;
typedef int SElemtype;
#define MAXSIZE 20


struct Stack
{
	SElemtype data[MAXSIZE];
	int top;
};

bool InitStack(Stack* s) {
	s->data[MAXSIZE] = {};
	s->top = -1;
	return true;
}

bool StackEmpty(Stack s) {
	if (s.top == -1)
	{
		return true;
	}
	return false;
}

int StackLength(Stack s) {
	return (s.top + 1);
}

bool Push(Stack* s, SElemtype e) {
	if (s->top == MAXSIZE)
	{
		cout << "ջ������" << endl;
		return false;
	}
	s->data[++s->top] = e;
	return true;
}

bool Pop(Stack* s, SElemtype* e) {
	if (s->top == -1) {
		cout << "ջ�ѿգ�" << endl;
		return false;
	}
	*e = s->data[s->top--];
	return true;
}

/*int main() {
	int j;
	Stack s;
	int e;
	if (InitStack(&s))
	{
		for (j = 1; j <= 5; j++)
			Push(&s, j);
	}

	printf("��ǰջ��Ԫ���У�%d \n", StackLength(s));

	Pop(&s, &e);
	printf("������ջ��Ԫ�� e=%d\n", e);
	printf("ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));
	return 0;
}*/