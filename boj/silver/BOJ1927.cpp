// BOJ 1927. 최소 힙 / S3
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>>q;

	int N;
	cin >> N;

	while (N--) {
		int num;
		cin >> num;

		if (num == 0) {
			if (!q.empty()) {
				cout << q.top() << "\n";
				q.pop();
			}
			else {
				cout << 0 << "\n";
			}
		}
		else q.push(num);
	}
}
/*
ios::sync_with_stdio(false);
cin.tie(nullptr);
이거 작성 안해서 시간초과 발생...

#include <queue>
우선순위 큐 (최대 힙)
priority_queue<int, vector<int>>q;

우선순위 큐 (최소 힙)
priority_queue<int, vector<int>, greater<int>>q;

*/