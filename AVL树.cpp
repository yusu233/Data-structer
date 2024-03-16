#include<iostream>
#include<algorithm>
using namespace std;

typedef int AVLTElemType;

class AVLTree
{
public:
	AVLTree() : AVLTreeRoot(nullptr) {}
	void insertelem(AVLTElemType value) {
		AVLTreeRoot = InsertAVLTree(AVLTreeRoot, value);
	}
	void deleteelem(AVLTElemType value) {
		AVLTreeRoot = DeleteAVLTree(AVLTreeRoot, value);
	}
private:
	//����AVL���Ľ��ṹ
    struct Node
    {
	  AVLTElemType data;
	  Node* lchild;
	  Node* rchild;
	  int height;
	  Node(AVLTElemType value) : data(value), lchild(nullptr), rchild(nullptr), height(1) {}
    };

	//������
	Node* AVLTreeRoot;

	//����߶�
	int height(Node* node) {
		return node == nullptr ? 0 : node->height;
	}

	//����ת����
	Node* RightRotate(Node* node) {
		Node* child = node->lchild;
		node->lchild = child->rchild;
		child->rchild = node;
		node->height = max(height(node->lchild), height(node->rchild)) + 1;
		child->height = max(height(child->lchild), height(child->rchild)) + 1;
		//������ת��������µĸ��ڵ�
		return child;
	}

	//����ת����
	Node* LeftRotate(Node* node) {
		Node* child = node->rchild;
		node->rchild = child->lchild;
		child->lchild = node;
		node->height = max(height(node->lchild), height(node->rchild)) + 1;
		child->height = max(height(child->lchild), height(child->rchild)) + 1;
		//������ת��������µĸ��ڵ�
		return child;
	}

	//��ƽ�⣨������ת������ת��
	Node* LeftBalance(Node* node) {
		node->lchild = LeftRotate(node->lchild);
		node = RightRotate(node);
		return node;
	}

	//��ƽ�⣨������ת������ת��
	Node* RightBalance(Node* node) {
		node->rchild = RightRotate(node->rchild);
		node = LeftRotate(node);
		return node;
	}

	//AVL������Ԫ��
	Node* InsertAVLTree(Node* T, AVLTElemType value) {
		if (!T){
		  Node* temp = new Node(value);
		  return temp;
		}
		else if (value < T->data) {
			T->lchild = InsertAVLTree(T->lchild, value);
			if (height(T->lchild) - height(T->rchild) > 1) {
				if (height(T->lchild->lchild) > height(T->lchild->rchild))
					T = RightRotate(T);
				else
					T = LeftBalance(T);
			}
		}
		else if (value > T->data) {
			T->rchild = InsertAVLTree(T->rchild, value);
			if (height(T->rchild) - height(T->lchild)> 1) {
				if (height(T->rchild->rchild) > height(T->rchild->lchild))
					T = LeftRotate(T);
				else
					T = RightBalance(T);
			}
		}
		//���½��߶�
		T->height = max(height(T->lchild), height(T->rchild)) + 1;
		return T;
	}

	//AVL��ɾ��Ԫ��
	Node* DeleteAVLTree(Node* T, AVLTElemType value) {
		if (!T)
			cout << "AVL���Ѿ�Ϊ�գ�" << endl;
		else if (value < T->data) {
			T->lchild = DeleteAVLTree(T->lchild, value);
			//���������ɾ����Ԫ��֮���Ƿ����ɲ�ƽ�⣬��ƽ��͸���Ϊƽ�������
			if (height(T->rchild) - height(T->lchild) > 1){
				if (height(T->rchild->lchild) > height(T->rchild->rchild))
					T = RightBalance(T);
				else
					T = LeftRotate(T);
			}
		}
		else if (value > T->data) {
			T->rchild = DeleteAVLTree(T->rchild, value);
			if (height(T->lchild) - height(T->rchild) > 1){
				if (height(T->lchild->lchild) >= height(T->lchild->rchild))
					T = RightRotate(T);
				else
					T = LeftBalance(T);
			}
		}
		else {
			if (T->lchild != nullptr && T->rchild != nullptr){
				//����ɾ�����֮���ʧ��������֣�ɾ�����������нϸߵ�һ��
				if (height(T->lchild) >= height(T->rchild)){
					Node* temp = T->lchild; 
					while (temp->rchild){
						temp = temp->rchild;
					}
					T->data = temp->data;
					T->lchild = DeleteAVLTree(T->lchild, temp->data);
				}
				else {
					Node* temp = T->rchild;
					while (temp->lchild){
						temp = temp->lchild;
					}
					T->data = temp->data;
					T->rchild = DeleteAVLTree(T->rchild, temp->data);
				}
			}
			else {
				if (T->lchild != nullptr) {
					T->data = T->lchild->data;
					delete T->lchild;
					T->lchild = nullptr;
				}
				else if(T->rchild != nullptr) {
					T->data = T->rchild->data;
					delete T->rchild;
					T->rchild = nullptr;
				}else{
					return nullptr;
				}
			}
		}
		T->height = max(height(T->lchild), height(T->rchild)) + 1;
		return T;
	}
};

int main() {
	AVLTree avl;
	//int test[10] = { 3, 2, 1, 4, 5, 6, 7, 10, 9, 8 };
	for (int i = 1; i < 11; i++)
	{
		avl.insertelem(i);
	}
	avl.deleteelem(9);
	avl.deleteelem(10);
	avl.deleteelem(6);
	avl.deleteelem(1);
	avl.deleteelem(2);
	avl.deleteelem(3);
	return 0;
}