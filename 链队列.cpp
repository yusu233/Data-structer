#include<iostream>
using namespace std;

typedef int QelemType;

//��������ṹ��
struct LinkNode
{
	QelemType data;
	LinkNode* next;
	LinkNode(int x): data(x), next(nullptr){}
};

//���������нṹ��
struct LinkQueue {
	LinkNode* front;
	LinkNode* rear;
};

//��ʼ��������
bool InitQueue(LinkQueue* q) {
	q->rear = q->front = new LinkNode(0);
	return true;
}

//�ж��������Ƿ�Ϊ��
bool QueueEmpty(LinkQueue q) {
	if (q.front == q.rear)
	{
		return true;
	}
	return false;
}

//���������
bool ClearQueue(LinkQueue* q) {
	q->rear = q->front;
	while (q->front->next)
	{
		LinkNode* temp = q->front->next;
		q->front->next = temp->next;
		delete temp;
	}
	return true;
}

//���еĳ���
int QueueLength(LinkQueue q) {
	int count = 0;
	LinkNode* temp = q.front->next;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
//ע���󳤶ȵ�ʱ��Ҫֱ��ʹ��frontָ�������������ı���еĽṹ��Ҳ����ʹ��temp->nexr = temp->next->next������Ҳ��ı���нṹ��

//���ض���ͷԪ��
bool GetHead(LinkQueue q, QelemType* e) {
	if (q.front == q.rear)
	{
		return false;
	}
	*e = q.front->next->data;
	return true;
}

//�ڶ�β����Ԫ��
bool AddQueue(LinkQueue* q, QelemType e) {
	LinkNode* n = new LinkNode(e);
	q->rear->next = n;
	q->rear = n;
	return true;
}

//ɾ����ͷԪ��
bool DelQueue(LinkQueue* q, QelemType* e) {
	if (q->front == q->rear)
	{
		return false;
	}
	LinkNode* temp = q->front->next;
	*e = temp->data;
	q->front->next = temp->next;
	//��ֹ��ɾ��βָ��rear
	if (q->rear == temp)
	{
		q->rear = q->front;
	}
	delete temp;
	return true;
}

/*int main()
{
	QelemType d;
	LinkQueue q;
	if (InitQueue(&q))
		printf("�ɹ��ع�����һ���ն���!\n");
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ", QueueEmpty(q));
	printf("���еĳ���Ϊ%d\n", QueueLength(q));
	AddQueue(&q, -5);
	AddQueue(&q, 5);
	AddQueue(&q, 10);
	printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n", QueueLength(q));
	printf("�Ƿ�ն��У�%d(1:�� 0:��)  ", QueueEmpty(q));
	if (GetHead(q, &d))
		printf("��ͷԪ���ǣ�%d\n", d);
	DelQueue(&q, &d);
	printf("ɾ���˶�ͷԪ��%d\n", d);
	if (GetHead(q, &d))
		printf("�µĶ�ͷԪ���ǣ�%d\n", d);
	ClearQueue(&q);
	printf("��ն��к�,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);
	return 0;
}*/