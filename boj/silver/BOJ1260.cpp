// BOJ 1260. DFS와 BFS / S2
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int s) {
    visited[s] = 1;
    cout << s << " ";

    for (int nxt : graph[s]) {
        if (visited[nxt] == 0) {
            dfs(nxt);
        }
    }
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int nxt : graph[cur]) {
            if (visited[nxt] == 0) {
                visited[nxt] = 1;
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> V;

    graph.assign(N + 1, {});
    visited.assign(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i < N + 1; i++) {
        if (graph[i].size() > 1) {
            sort(graph[i].begin(), graph[i].end());
        }
    }

    dfs(V);
    cout << "\n";

    visited.assign(N + 1, 0);
    bfs(V);
}

/*
DFS와 BFS를 둘다 함수화하여 활용
함수화 진행하며 방문한 노드를 순서대로 출력하기 위해 중간에 cout을 진행
방문할 수 있는 노드가 여러개일 때 노드의 숫자가 작은 것부터 가야하기 떄문에 graph[]를 모두 정렬 진행함
이후 DFS 함수 진행
vistied를 0으로 초기화 후
BFS 함수 진행
*/