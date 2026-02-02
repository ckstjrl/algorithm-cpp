// BOJ 1389. 케빈 베이컨의 6단계 법칙 / S1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> graph;

int bfs(int start) {
	vector<int> dist(N + 1, -1);
	queue<int> q;

	q.push(start);
	dist[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : graph[cur]) {
			if (dist[nxt] == -1) {
				dist[nxt] = dist[cur] + 1;
				q.push(nxt);
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < N + 1; i++) {
		sum += dist[i];
	}

	return sum + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	graph.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	vector<int> bacon(N);

	for (int i = 1; i < N + 1; i++) {
		bacon[i - 1] = bfs(i);
	}

	cout << min_element(bacon.begin(), bacon.end()) - bacon.begin() + 1 << "\n";
}

/*
하나의 숫자에서 모든 숫자에 가는 방법을 기록해야함
BFS 알고리즘 활용
이 방법을 통해 bacon 배열을 채우고 그 배열의 최솟값 인덱스 + 1을 진행하여 값을 출력함
*/