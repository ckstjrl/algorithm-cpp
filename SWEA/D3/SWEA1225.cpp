// SWEA 1225. 암호생성기 / D3
#include <iostream>
#include <queue>

using namespace std;

int main() {
	int T = 10;
	while (T--) {
		int tc;
		cin >> tc;

		int n = 8;
		queue<int> q;
		while (n--) {
			int num;
			cin >> num;
			q.push(num);
		}

		while (1) {
			int a;
			for (int i = 1; i <= 5; i++) {
				a = q.front() - i;
				q.pop();
				if (a < 0)a = 0;
				q.push(a);
				if (a == 0)break;
			}
			if (a == 0)break;
		}

		cout << "#" << tc;
		while(!q.empty()) {
			cout << ' ' << q.front();
			q.pop();
		}
		cout << "\n";
	}
}

/*
자료구조 queue 활용
8개의 수를 먼저 집어 넣고
a = q.front() - i가 0이 될 때까지 무한 반복 진행
i의 경우 1 ~ 5 를 계속 반복함
*/