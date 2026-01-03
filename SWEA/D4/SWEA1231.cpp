// SWEA 1231. 중위순회 / D4
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

char value[101];
int left_I[101] = { 0 };
int right_I[101] = { 0 };

void inorder(int node) {
	if (node == 0) return;
	inorder(left_I[node]);
	cout << value[node];
	inorder(right_I[node]);
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int N;
		cin >> N;
		cin.ignore();

		for (int i = 0; i < 101; i++) {
			value[i] = 0;
			left_I[i] = 0;
			right_I[i] = 0;
		}

		for (int i = 0; i < N; i++) {
			string line;
			getline(cin, line);    // 한 줄 전체를 문자열로 읽음 (공백 포함)

			stringstream ss(line);    // line을 "입력 스트림"처럼 취급하게 해줌

			int idx;
			ss >> idx >> value[idx];    // 노드 번호, 문자
			ss >> left_I[idx];    // 있으면 읽고, 없으면 실패 -> 값 변화 없음
			ss >> right_I[idx];    // 있으면 읽고, 없으면 실패 -> 값 변화 없음
		}

		cout << "#" << tc << ' ';
		inorder(1);
		cout << "\n";
	}
}

/*
트리 자료구조 중위 순회
binary tree 자료구조 제작
input으로
8 // 총 노드 수
1 W 2 3 // 1번 노드 값은 W / 왼쪽 자식 노드 번호 2번 / 오른쪽 자식 노드 번호 3번
2 F 4 5
3 R 6 7
4 O 8
5 T
6 A
7 E
8 S

이런 형식으로 제공받음

string line;
getline(cin, line);

stringstream ss(line);

int idx;
ss >> idx >> value[idx];
ss >> left_I[idx];
ss >> right_I[idx];
를 활용해 한줄씩 input을 받고
sstream을 활용하여 값을 저장

이후
inorder 함수를 통해 재귀 활용 중위 순회 진행
void inorder(int node) {
	if (node == 0) return;
	inorder(left_I[node]);
	cout << value[node];
	inorder(right_I[node]);
}

전위 순회
void inorder(int node) {
	if (node == 0) return;
	cout << value[node];
	inorder(left_I[node]);
	inorder(right_I[node]);
}

후위 순회
void inorder(int node) {
	if (node == 0) return;
	inorder(left_I[node]);
	inorder(right_I[node]);
	cout << value[node];
}
*/