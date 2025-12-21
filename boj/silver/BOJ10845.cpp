// BOJ 10845. 큐 / S4
#include <iostream>
#include <queue>

using namespace std;
queue<int> q;
int main() {
	int N;
	cin >> N;
	
	while(N--){
		string p;
		int num;
		cin >> p;

		if (p == "push") {
			cin >> num;
			q.push(num);
		}

		else if (p == "pop") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}

		else if (p == "size") {
			cout << q.size() << "\n";
		}

		else if (p == "empty") {
			if (q.empty()) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}

		else if (p == "front") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.front() << "\n";
			}

		}

		else if (p == "back") {
			if (q.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << q.back() << "\n";
			}

		}
	
	}
}

/*
C++ 자료구조 큐 활용 -> 선입선출
queue.push(num) -> 큐에 num 삽입
queue.pop() -> 가장 처음 집어 넣은 수를 뽑아냄, 리턴 값 없음
queue.size() -> 큐의 사이즈 리턴
queue.empty() -> 비어 있으면 1, 아니면 0 리턴
queue.front() -> 가장 먼저 들어와 있는 요소 리턴
queue.back() -> 가장 마지막으로 들어온 요소 리턴
*/