// BOJ 15681. 트리와 쿼리 / G5
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, R, Q;
	cin >> N >> R >> Q;

	vector<vector<int>> graph(N + 1);

	for (int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<int> parent(N + 1, -1);
	vector<int> order;

	queue<int> q;
	q.push(R);
	parent[R] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		order.push_back(cur);

		for (int nxt : graph[cur]) {
			if (parent[nxt] == -1) {
				parent[nxt] = cur;
				q.push(nxt);
			}
		}
	}
	
	vector<int> subtree(N + 1, 1);
	for (int i = N - 1; i >= 0; i--) {
		int c = order[i];
		int p = parent[c];
		if (p != 0) subtree[p] += subtree[c];
	}

	while (Q--) {
		int s;
		cin >> s;
		cout << subtree[s]<<"\n";
	}
	
}

/*
일단 트리가 주어지는 형태가 누가 부모 노드이고 누가 자식 노드인지 알 수 없음
graph 이차원 벡터에 간선으로 연결되어있는 모든 노드를 작성한 후
R 루트 번호를 활용해 BFS 알고리즘으로 부모 노드를 각 인덱스에 작성함
작성하는 과정에서 order에 순서대로 집어 넣게 되면 자연스럽게 부모노드가 자식노드보다 앞 인덱스에 들어가게됨
이걸 거꾸로 읽으면서 subtree[p] += subtree[c] 이 연산을 하게 되면 해당 노드를 루트로 하는 서브트리의 총 노드 개수를 알 수 있음
*/