#include<iostream>
using namespace std;

typedef int EdgeType;
#define Maxarc 4
#define INFINITY 65535

//����ͼ�Ĵ洢�ṹ���ڽӾ���
struct GraphAdj
{
	EdgeType adj[Maxarc][Maxarc];
};

void CreateGraph(GraphAdj* G) {
	int i, j, count;
	int start, end, weight;
	 char x;

	//��ʼ���ڽӾ���
	cout << "����ͼ�Ķ���������" << endl;
	cin >> count;
	for (i = 0; i < count; i++){
		for (j = 0; j < count; j++) {
			G->adj[i][j] = INFINITY;
		}
	}

	//��������ͼ�ڽӾ���
	cout << "����ߵ���ʼ���㣬 ��ֹ���㣬 Ȩֵ(����q��ֹ)�� " << endl;
	while (true)
	{
		cin >> x;
		if (x == 'q')
			break;
		start = atoi(&x);
		cin >> end >> weight;
		G->adj[start][end] = weight;
		G->adj[end][start] = G->adj[start][end];
		cout << "����ߵ���ʼ���㣬 ��ֹ���㣬 Ȩֵ�� " << endl;
	}
}

int main() {
	GraphAdj G;
	CreateGraph(&G);
	return 0;
}