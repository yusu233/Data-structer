#include<iostream>

using namespace std;
#define MAXSIZE 20
typedef int QelemType;

//������н�ṹ
struct Queue {
	QelemType data[MAXSIZE];
	int front, rear;
};

//��ʼ������
bool InitQueue(Queue* q) {
	q->front = 0;
	q->rear = 0;
	return true;
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue q) {
	if (q.front == q.rear)
	{
		return true;
	}
	return false;
}

//����еĴ�С
int QueueLength(Queue q) {
	return (q.rear - q.front + MAXSIZE) % MAXSIZE;
}

//���еĵ�һ��ֵ
bool GetHead(Queue q, QelemType* e) {
	if (q.front == q.rear)
	{
		cout << "����Ϊ�գ�" << endl;
		return false;
	}
	*e = q.data[q.front];
	return true;
}

//�ڶ�β����Ԫ��
bool AddQueue(Queue* q, QelemType e) {
	if ((q->rear + 1) % MAXSIZE == q->front)
	{
		cout << "����������" << endl;
		return false;
	}
	q->data[q->rear] = e;
	q->rear = (++q->rear) % MAXSIZE;
	return true;
}

//���ز�ɾ����ͷ��Ԫ��
bool DelQueue(Queue* q, QelemType* e) {
	if (q->front == q->rear)
	{
		return false;
	}
	*e = q->data[q->front];
	q->front = (++q->front) % MAXSIZE;
	return true;
}

/*int main()
{
	int i = 0, l;
	QelemType d;
	Queue Q;
	InitQueue(&Q);
	printf("��ʼ�����к󣬶��пշ�%u(1:�� 0:��)\n", QueueEmpty(Q));

	printf("���������Ͷ���Ԫ��(������%d��),-1Ϊ��ǰ������: ", MAXSIZE - 1);
	do
	{
		d = i + 100;
		if (d == -1)
			break;
		i++;
		AddQueue(&Q, d);
	} while (i < MAXSIZE - 1);

	printf("���г���Ϊ: %d\n", QueueLength(Q));
	printf("���ڶ��пշ�%u(1:�� 0:��)\n", QueueEmpty(Q));
	printf("����%d���ɶ�ͷɾ��Ԫ��,��β����Ԫ��:\n", MAXSIZE);
	for (l = 1; l <= MAXSIZE; l++)
	{
		DelQueue(&Q, &d);
		printf("ɾ����Ԫ����%d,�����Ԫ��:%d \n", d, l + 1000);
		// scanf("%d",&d); 
		d = l + 1000;
		AddQueue(&Q, d);
	}
	l = QueueLength(Q);

	printf("�����β������%d��Ԫ��\n", i + MAXSIZE);
	if (l - 2 > 0)
		printf("�����ɶ�ͷɾ��%d��Ԫ��:\n", l - 2);
	while (QueueLength(Q) > 2)
	{
		DelQueue(&Q, &d);
		printf("ɾ����Ԫ��ֵΪ%d\n", d);
	}

	bool j = GetHead(Q, &d);
	if (j)
		printf("���ڶ�ͷԪ��Ϊ: %d\n", d);
	return 0;
}*/

