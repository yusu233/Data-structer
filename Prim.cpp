#include<iostream>
using namespace std;

#define INFINITY 65535
#define MAXSIZE 9

struct Graph{
	int arc[MAXSIZE][MAXSIZE];
	int VertexNum, EdgeNum;
};

void CreateMGraph(Graph* G){
	G->EdgeNum = 15;
	G->VertexNum = 9;

	for (int i = 0; i < G->VertexNum; i++)
	{
		for (int j = 0; j < G->VertexNum; j++)
		{
			if (i == j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = G->arc[j][i] = INFINITY;
		}
	}

	G->arc[0][1] = 10;
	G->arc[0][5] = 11;
	G->arc[1][2] = 18;
	G->arc[1][8] = 12;
	G->arc[1][6] = 16;
	G->arc[2][8] = 8;
	G->arc[2][3] = 22;
	G->arc[3][8] = 21;
	G->arc[3][6] = 24;
	G->arc[3][7] = 16;
	G->arc[3][4] = 20;
	G->arc[4][7] = 7;
	G->arc[4][5] = 26;
	G->arc[5][6] = 17;
	G->arc[6][7] = 19;

	for (int i = 0; i < G->VertexNum; i++)
	{
		for (int j = i; j < G->VertexNum; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}

}

void MinSpanTree_Prim(Graph G) {
	int parent[MAXSIZE];  //�洢��С������
	int distance[MAXSIZE];  //�洢��������С�������ľ���

	//��ʼ������parent��distance
	parent[0] = -1;
	for (int i = 1; i < G.VertexNum; i++){
		distance[i] = G.arc[0][i];
		parent[i] = 0;
	}

	//������С������
	for (int i = 1; i < G.VertexNum; i++){
		//Ѱ�Ҿ�����С�����������δ��¼����
		int min = INFINITY;
		int minvex = 0;
		for (int j = 1; j < G.VertexNum; j++){
			if (distance[j] != 0 && distance[j] < min) {
				min = distance[j];
				minvex = j;
			}
		}

		cout << "(" << parent[minvex] << "," << minvex << ")" << endl;
		//����������Ķ��������С������
		distance[minvex] = 0;

		//����δ��¼��������С�������ľ���
		for (int l = 1; l < G.VertexNum; l++){
			if (distance[l] != 0 && G.arc[minvex][l] < distance[l]) {
				distance[l] = G.arc[minvex][l];
				parent[l] = minvex;
			}
		}
	}
}

int main() {
	Graph G;
	CreateMGraph(&G);
	MinSpanTree_Prim(G);
	return 0;
}