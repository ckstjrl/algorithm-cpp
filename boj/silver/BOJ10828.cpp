// BOJ 10838. 스택 / S4

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	stack<int> s;

	while (N--) {
		string p;
		int num;
		cin >> p;

		if (p == "push") {
			cin >> num;
			s.push(num);
		}

		else if (p == "pop") {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else {
				int a = s.top();
				s.pop();
				cout << a << "\n";
			}
		}

		else if (p == "size") {
			cout << s.size() << "\n";
		}

		else if (p == "empty") {
			if (s.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}

		else if (p == "top") {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << s.top() << "\n";
			}
		}
	}
}

/*
C++ 자료구조 stack 사용
s.push(m) -> m을 스택에 집어 넣음
s.pop() -> 가장 최근에 들어온 요소를 삭제, 리턴 값 없음
s.top() -> 가장 최근에 들어온 요소를 리턴
s.size() -> 스택에 있는 요소 수를 리턴
s.empty() -> 비어있다면 1, 아니면 0 리턴
*/