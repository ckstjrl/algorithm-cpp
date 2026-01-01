// BOJ 28279. 덱 2 / S4
#include <iostream>
#include <deque>

using namespace std;

deque<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	while (N--) {
		int a;
		cin >> a;

		if (a == 1) {
			int b;
			cin >> b;
			q.push_front(b);
		}

		else if (a == 2) {
			int b;
			cin >> b;
			q.push_back(b);
		}

		else if (a == 3) {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop_front();
			}
			else cout << -1 << "\n";
		}

		else if (a == 4) {
			if (!q.empty()) {
				cout << q.back() << "\n";
				q.pop_back();
			}
			else cout << -1 << "\n";
		}

		else if (a == 5) {
			cout << q.size() << "\n";
		}

		else if (a == 6) {
			if (!q.empty()) cout << 0 << "\n";
			else cout << 1 << "\n";
		}

		else if (a == 7) {
			if (!q.empty()) {
				cout << q.front() << "\n";
			}
			else cout << -1 << "\n";
		}

		else if (a == 8) {
			if (!q.empty()) {
				cout << q.back() << "\n";
			}
			else cout << -1 << "\n";
		}
	}
}

/*
ios::sync_with_stdio(false);
cin.tie(nullptr);

fast io를 작성 안해서 시간초과 발생
어떤 기준인지 모르겠음... 항상 써야하는 건가. 의문이 크게 듦

자료구조 deque 정리
deque는 stack, queue와 다르게 앞 뒤로 요소를 넣고 뺄 수 있음
q.push_front(i) : i를 q의 맨 앞에 넣는다.
q.push_back(i) : i를 q의 맨 뒤에 넣는다.
q.front() : q의 맨 앞의 요소 리턴
q.back() : q의 맨 뒤의 요소 리턴
q.pop_front() : q의 맨 앞 요소 삭제, 리턴 X
q.pop_back() : q의 맨 뒤 요소 삭제, 리턴 X
q.size() : q의 요소 개수 리턴
q.empty() : q가 비어있다면 true, 아니라면 false 리턴
*/