#include<iostream>
using namespace std;

typedef int HeapElemTpye;
#define MaxData INT_MAX;

//ʹ������
class Heap
{
public:
	Heap() : heap(nullptr){}

	void create(int capacity) {
		heap = InitHeap(capacity);
	}

	void insert(HeapElemTpye value) {
		Insert(heap, value);
	}
	void traverse() {
		Traverse(*heap);
	}
	
	HeapElemTpye deleteheap() {
		return Delete(heap);
	}

private:
	//����ѽṹ
	struct HeapStruct {
		HeapElemTpye* Elements_;//�洢�ѵ�����
		int size_;//�ѵ�ǰ��Ԫ�ظ���
		int Maxsize_;//�ѵ��������
	};

	//��������ʼ����
	HeapStruct* InitHeap(int capacity) {
		HeapStruct* H = new HeapStruct;
		H->Elements_ = new HeapElemTpye[capacity + 1];
		H->size_ = 0;
		H->Maxsize_ = capacity;
		H->Elements_[0] = MaxData;
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

	//���ѵĲ���
	void Insert(HeapStruct* H, HeapElemTpye value) {
		int index;
		if (HeapFull(*H))
			cout << "��������" << endl;
		index = ++H->size_;
		for (; H->Elements_[index / 2] < value && index > 1; index /= 2)
			H->Elements_[index] = H->Elements_[index / 2];
		H->Elements_[index] = value;
	}

	//���ѵ�ɾ��
	HeapElemTpye Delete(HeapStruct* H) {
		int parent, child;
		HeapElemTpye root, temp;
		if (HeapEmpty(*H)){
			cout << "����Ϊ�գ�" << endl;
			return -1;
		}
		root = H->Elements_[1];
		temp = H->Elements_[H->size_--];
		for (parent = 1; parent * 2 <= H->size_; parent = child){
			child = 2 * parent;
			//�ҳ����ҽ������ֵ
			if (child != H->size_ && H->Elements_[child] < H->Elements_[child + 1])
				child++;
			if (temp >= H->Elements_[child])
				break;
			else
				H->Elements_[parent] = H->Elements_[child];
		}
		H->Elements_[parent] = temp;
		return root;
	}

	//���ѵı���
	void Traverse(HeapStruct H) {
		for (int i = 0; i <= H.size_; i++)
			cout << H.Elements_[i] << endl;
	}

	HeapStruct* heap;
};

int main() {
	Heap test;

	test.create(9);
	test.insert(90);
	test.insert(70);
	test.insert(80);
	test.insert(60);
	test.insert(100);
	test.traverse();

	test.deleteheap();
	test.traverse();
	return 0;
}