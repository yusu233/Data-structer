#include<iostream>
using namespace std;

typedef int HElemType;
#define MinData INT_MIN

//��������������Ľṹ
struct HTNode {
	HElemType data;
	int weight;
	HTNode* lchild;
	HTNode* rchild;
};


//�������ڹ��������������С��
class Heap
{
public:
	Heap() : heap(nullptr) {}

	void create(int capacity) {
		heap = InitHeap(capacity);
	}

	void insert(HTNode* value) {
		Insert(heap, value);
	}

	void traverse() {
		Traverse(*heap);
	}

	HTNode* deleteheap() {
		return Delete(heap);
	}

	int Getsize() {
		return heap->size_;
	}

private:

	//����ѽṹ
	struct HeapStruct {
		HTNode* Elements_;//�洢�ѵ�����
		int size_;//�ѵ�ǰ��Ԫ�ظ���
		int Maxsize_;//�ѵ��������
	};

	//��������ʼ����
	HeapStruct* InitHeap(int capacity) {
		HeapStruct* H = new HeapStruct;
		H->Elements_ = new HTNode[capacity + 1];
		H->size_ = 0;
		H->Maxsize_ = capacity;
		H->Elements_[0].weight = MinData;
		return H;
	}

	//�ж϶��Ƿ�����
	bool HeapFull(HeapStruct H) {
		if (H.size_ == H.Maxsize_)
			return true;
		return false;
	}

	//�ж϶��Ƿ�Ϊ��
	bool HeapEmpty(HeapStruct H) {
		if (H.size_ == 0)
			return true;
		return false;
	}

	//��С�ѵĲ���
	void Insert(HeapStruct* H, HTNode* value) {
		int index;
		if (HeapFull(*H))
			cout << "��������" << endl;
		index = ++H->size_;
		for (; H->Elements_[index / 2].weight > value->weight && index > 1; index /= 2)
			H->Elements_[index] = H->Elements_[index / 2];
		H->Elements_[index] = *value;
	}

	//��С�ѵ�ɾ��
	HTNode* Delete(HeapStruct* H) {
		int parent, child;
		HTNode* root, *temp;
		if (HeapEmpty(*H)) {
			cout << "����Ϊ�գ�" << endl;
			return ;
		}
		*root = H->Elements_[1];
		*temp = H->Elements_[H->size_--];
		for (parent = 1; parent * 2 <= H->size_; parent = child) {
			child = 2 * parent;
			//�ҳ����ҽ�����Сֵ
			if (child != H->size_ && H->Elements_[child].weight > H->Elements_[child + 1].weight)
				child++;
			if (temp->weight <= H->Elements_[child].weight)
				break;
			else
				H->Elements_[parent] = H->Elements_[child];
		}
		H->Elements_[parent] = *temp;
		return root;
	}

	//��С�ѵı���
	void Traverse(HeapStruct H) {
		for (int i = 0; i <= H.size_; i++)
			cout << H.Elements_[i].data << endl;
	}

	HeapStruct* heap;
};

//�����������캯��
HTNode* Huffman(Heap* H) {
	int i;
	HTNode* T;
	for ( i = 1; i < H->Getsize(); i++){
		T = new HTNode;
		T->lchild = H->deleteheap();
		T->rchild = H->deleteheap();
		T->weight = T->lchild->weight + T->rchild->weight;
		H->insert(T);
	}
	T = H->deleteheap();
	return T;
}

int main() {
	HTNode* array[10];
	Heap* H;
	for (int i = 0; i < 9; i++){
		H->insert(array[i]);
	}
	Huffman(H);
	H->traverse();
	return 0;
}
