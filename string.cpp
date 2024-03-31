#include<iostream>
using namespace std;

#define MAXSIZE 40
typedef char String[MAXSIZE + 1];

void show(String T) {
	if (T[0] != 0) {
		for (int i = 1; i <= T[0]; i++)
		{
			cout << T[i];
		}
		cout << endl;
	}
}

//����ֵΪchars���ַ���
bool StrAssign(String T, const char* chars) {
	if (strlen(chars) > MAXSIZE)
		return false;
	else {
		T[0] = strlen(chars);
		for (int i = 1; i <= T[0]; i++)
			T[i] = chars[i - 1];
		return true;
	}
}

//�����ַ���
bool StrCopy(String T, String S) {
	for (int i = 0; i <= S[0]; i++){
		T[i] = S[i];
	}
	return true;
}

//�ж��ַ�������
int StrLength(String S) {
	return S[0];
}

//����ַ���
void StrClear(String S) {
	S[0] = 0;
}

//ƴ���ַ���
bool StrConcat(String T, String S) {
	if (T[0] + S[0] <= MAXSIZE){
		for (int i = 1; i <= S[0]; i++)
			T[T[0] + i] = S[i];
		T[0] += S[0];
		return true;
	}
	else {
		for (int i = 1; i <= MAXSIZE - T[0]; i++)
			T[T[0] + i] = S[i];
		T[0] = MAXSIZE;
		return false;
	}
}

//���ش�S�еĵ�pos���ַ��𳤶�Ϊlen���ִ�
void SubString(String S, String Sub, int pos, int len) {
	if (pos + len - 1 > S[0] ||pos < 1 || pos > Sub[0] || len < 0) {}
	else{
		S[0] = len;
		for (int i = 1; i <= len; i++){
			S[i] = Sub[pos + i - 1];
		}
	}
}

//�����ִ�T������S�е�pos���ַ�֮���λ��
int IndexString(String T, String S, int pos) {
	int index = pos;
	int n = 1, start = pos;
	if (pos < 1 || pos > S[0]){
		return -1;
	}
	else{
		while (index <= S[0] && n <=T[0]){
			if (S[index] == T[n]){
				index++;
				n++;
			}
			else{
				index = ++start;
				n = 1;
			}
		}
		if (n > T[0]){
			return index - T[0];
		}//�ɹ�
		return 0;
	}
}

char* StrAssign1(String T, const char* chars) {
	if (strlen(chars) > MAXSIZE)
		return nullptr;
	else {
		T[0] = strlen(chars);
		for (int i = 1; i <= T[0]; i++)
			T[i] = chars[i - 1];
		return T;
	}
}

int main() {
	String T = {};
	String S = {};
	String P = {};
	
	char* R = StrAssign1(S, "dddd");
	show(R);
    StrAssign(S, "abcdef");
	show(S);
	cout << endl << StrLength(S) << endl;

	StrCopy(T, S);
	show(T);

	StrConcat(T, S);
	show(T);

	StrAssign(P, "abcdefghijkdef");
	SubString(T, P, 4, 3);
	show(T);

	StrAssign(T, "defg");
	cout << IndexString(T, P, 7);

	return 0;
}