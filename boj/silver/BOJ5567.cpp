// BOJ 5567. 결혼식 / S2
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> graph(N+1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	queue<int> q;
	vector<int> visited(N+1, -1);
	q.push(1);
	visited[1] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int nxt : graph[cur]) {
			if (visited[nxt] == -1) {
				q.push(nxt);
				visited[nxt] = visited[cur] + 1;
			}
		}
	}
    
    int cnt = 0;
    for (int v : visited) {
        if (v == 1 || v == 2) {
            cnt++;
        }
    }
    
	cout << cnt << "\n";
}

/*
BFS 활용
상근이 친구들을 전부 graph에 친구 관계로 작성하고
BFS를 사용하여 상근이와 몇번 걸쳐서 친구인지 파악
이후 1, 2값을 가지고 있는 친구들의 숫자를 세서 출력
*/