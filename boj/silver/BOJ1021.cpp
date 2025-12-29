// BOJ 1021. 회전하는 큐 / S3
#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	queue<int> num;
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		num.push(n);
	}

	deque<int> q(N);
	for (int i = 1; i <= N; i++) {
		q[i-1] = i;
	}

	int cnt = 0;
	while (!num.empty()) {
		int n = num.front();

		if (n == q.front()) {
			q.pop_front();
			num.pop();
		}
		else {
			int pos = 0;
			for (int i = 0; i < q.size(); i++) {
				if (n == q[i]) {
					pos = i;
					break;
				}
			}

			if (pos <= q.size() / 2) {
				cnt += pos;
				while (pos--) {
					int temp = q.front();
					q.push_back(temp);
					q.pop_front();
				}
			}
			else {
				int move = q.size() - pos;
				cnt += move;
				while (move--) {
					int temp = q.back();
					q.push_front(temp);
					q.pop_back();
				}
			}
		}
	}
	cout << cnt << "\n";
}

/*
자료구조 queue와 deque 사용
deque은 앞뒤로 넣고 뺄 수 있는 자료 구조라 문제의 2번, 3번 동작 수행 가능
뽑아야 하는 숫자들을 queue에 집어 넣고 deque에는 1부터 N까지의 숫자를 집어 넣음
while문을 통해서 queue의 모든 요소가 없어질때 까지 반복을 진행
queue에서 숫자를 뽑아서 해당 숫자가 deque의 맨 앞에 있는지 확인한 후
그게 아니라면,
현재 인덱스(pos)를 찾아서 pos가 deque의 사이즈 / 2 보다 작거나 같으면 2번을 pos번 진행
pos가 deque 사이즈 / 2 보다 크다면 3번을 deque의 사이즈 - pos번 진행 하는 방식으로 수행
*/