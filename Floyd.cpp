#include<iostream>
#include<stack>
using namespace std;

#define MAXSIZE 9
#define INFINITY 65535

typedef int Path[MAXSIZE][MAXSIZE];
typedef int ShortPathTable[MAXSIZE][MAXSIZE];


class Graph
{
public:
	int VertexNum_, EdgeNum_;
	int arc_[MAXSIZE][MAXSIZE];
	char vertex_[MAXSIZE];
	//����ͼ
	void CreateGraph() {
		VertexNum_ = 9;
		EdgeNum_ = 32;

		for (int i = 0; i < VertexNum_; i++)/* ��ʼ��ͼ */
		{
			vertex_[i] = i;
		}

		for (int i = 0; i < VertexNum_; i++)/* ��ʼ��ͼ */
		{
			for (int j = 0; j < VertexNum_; j++)
			{
				if (i == j)
					arc_[i][j] = 0;
				else
					arc_[i][j] = arc_[j][i] =INFINITY;
			}
		}

		arc_[0][1] = 1;
		arc_[0][2] = 5;
		arc_[1][2] = 3;
		arc_[1][3] = 7;
		arc_[1][4] = 5;

		arc_[2][4] = 1;
		arc_[2][5] = 7;
		arc_[3][4] = 2;
		arc_[3][6] = 3;
		arc_[4][5] = 3;

		arc_[4][6] = 6;
		arc_[4][7] = 9;
		arc_[5][7] = 5;
		arc_[6][7] = 2;
		arc_[6][8] = 7;

		arc_[7][8] = 4;


		for (int i = 0; i < VertexNum_; i++)
		{
			for (int j = i; j < VertexNum_; j++)
			{
				arc_[j][i] = arc_[i][j];
			}
		}


		/*//�ڽӾ���
		vertex_[0] = '0';
		vertex_[1] = '1';
		vertex_[2] = '2';
		vertex_[3] = '3';
		vertex_[4] = '4';
		vertex_[5] = '5';
		vertex_[6] = '6';
		vertex_[7] = '7';
		vertex_[8] = '8';


		for (int i = 0; i < VertexNum_; i++) {
			for (int j = 0; j < VertexNum_; j++) {
				arc_[i][j] = INFINITY;
			}
		}

		for (int i = 0; i < VertexNum_; i++)
			arc_[i][i] = 0;

		arc_[0][2] = 5;
		arc_[0][1] = 1;

		arc_[1][0] = 1;
		arc_[1][2] = 3;
		arc_[1][3] = 7;
		arc_[1][4] = 5;

		arc_[2][0] = 5;
		arc_[2][1] = 3;
		arc_[2][4] = 1;
		arc_[2][5] = 7;

		arc_[3][1] = 7;
		arc_[3][4] = 2;
		arc_[3][6] = 3;

		arc_[4][1] = 5;
		arc_[4][2] = 1;
		arc_[4][3] = 2;
		arc_[4][5] = 3;
		arc_[4][6] = 6;
		arc_[4][7] = 9;

		arc_[5][2] = 7;
		arc_[5][4] = 3;
		arc_[5][7] = 5;

		arc_[6][3] = 3;
		arc_[6][4] = 6;
		arc_[6][7] = 2;
		arc_[6][8] = 7;

		arc_[7][4] = 9;
		arc_[7][5] = 7;
		arc_[7][6] = 2;
		arc_[7][8] = 4;

		arc_[8][6] = 7;
		arc_[8][7] = 4;*/
	}

};

void ShortestPsth_Floyd(Graph G, Path* P, ShortPathTable* D) {
	//��ʼ����Ȩ����D��·��P
	for (int i = 0; i < G.VertexNum_; i++){
		for (int j = 0; j < G.VertexNum_; j++) {
			(*P)[i][j] = j;
			(*D)[i][j] = G.arc_[i][j];
		}
	}

	//��������
	for (int k = 0; k < G.VertexNum_; k++){
		for (int v = 0; v < G.VertexNum_; v++) {
			for (int w = 0; w < G.VertexNum_; w++) {
				if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w]){
					(*D)[v][w] = (*D)[v][k] + (*D)[k][w];
					(*P)[v][w] = k;
				}
			}
		}
	}
}

int main() {
	Graph G;
	Path P;
	ShortPathTable D;
	G.CreateGraph();
	ShortestPsth_Floyd(G, &P, &D);
	return 0;
}