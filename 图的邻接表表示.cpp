#include<iostream>
using namespace std;

#define Max 5

//����ṹ
struct Verteexlist{
	int vertex;
	Adjlist* firstedge;
};

//�߱�ṹ
struct Adjlist{
	int adjvex;
	int weight;
	Adjlist* next;
};

struct Graph{
	Verteexlist array[Max];
	int vertexNum, EdgeNum;
};

void CrateGraph(Graph* G) {
	int i, j, k;
	cout << "���붥�����ͱ���: " << endl;
	cin >> G->vertexNum >> G->EdgeNum;
	for (i = 0; i < G->vertexNum; i++){
		cout << "�����" << i + 1 << "������: ";
		cin >> G->array[i].vertex;
		G->array[i].firstedge = nullptr;
	}

	Adjlist* e;
	int start, end, weight;
	for (k = 0; k < G->EdgeNum; k++){
		cout << "�����" << k + 1 << "������ʼ�㡢��ֹ���Ȩֵ��";
		cin >> start >> end >> weight;
		e = new Adjlist;
		e->adjvex = end;
		e->weight = weight;
		e->next = G->array[start].firstedge;
		G->array[start].firstedge = e;
	}
}