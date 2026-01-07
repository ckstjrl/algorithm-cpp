// BOJ 11724. 연결 요소의 개수 / S2
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N+1);
	vector<int> visited(N+1, 0);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].emplace_back(v);
		graph[v].emplace_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			queue<int> q;
			q.push(i);
			visited[i] = 1;
			
			while (!q.empty()) {
				int x = q.front();
				q.pop();

				for (int nxt : graph[x]) {
					if (visited[nxt] == 0) {
						visited[nxt] = 1;
						q.push(nxt);
					}
				}
			}
			cnt++;
		}
	}
	cout << cnt << "\n";
}

/*
graph를 만들고 node index에 연결된 node 번호들을 넣어줘서 배열 만듦
이후 BFS를 활용해서 순환
while문이 돌아가는 횟수 = 연결된 node 묶음 개수
*/