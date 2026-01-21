// BOJ 2644. 촌수계산 / S2
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N, a, b, M;
	cin >> N >> a >> b >> M;

	vector<vector<int>> family(N + 1);
	for (int i = 0; i < M; i++) {
		int p, c;
		cin >> p >> c;
		family[c].push_back(p);
		family[p].push_back(c);
	}

	queue<int> q;
	q.push(a);
	vector<int> visited(N + 1, -1);
	visited[a] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for (int nxt : family[cur]) {
			if (visited[nxt] == -1) {
				visited[nxt] = visited[cur] + 1;
				q.push(nxt);
			}
		}
	}
	cout << visited[b] << "\n";
}

/*
가족 관계를 모두 family 그래프에 넣어줌
BFS를 활용하여 a와 다른 가족 구성원의 촌수를 visited에 작성
이후 visited[b]를 출력하면 a와 b사이 촌수가 나옴.
*/