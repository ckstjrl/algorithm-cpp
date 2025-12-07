#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;              // 정점 수, 간선 수
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    vector<int> dist(N + 1, -1);  // -1: 아직 방문 안 함

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);  // 무방향 그래프일 경우
    }

    int start = 1;
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : adj[cur]) {
            if (dist[nxt] != -1) continue;  // 이미 방문
            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }

    // dist[i] : start에서 i까지 최단 거리
    return 0;
}
