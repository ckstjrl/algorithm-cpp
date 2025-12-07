#include <iostream>
#include <vector>
#include <queue>    // priority_queue
#include <utility>  // pair

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;  // 정점, 간선
    cin >> N >> M;

    // adj[u] = {v, w} (u -> v 가중치 w)
    vector<vector<pair<int,int>>> adj(N + 1);
    vector<int> dist(N + 1, INF);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        // 방향 그래프면 위 한 줄만, 무방향이면 아래도
        // adj[b].push_back({a, c});
    }

    int start = 1;
    dist[start] = 0;

    // {비용, 정점}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, start});

    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (dist[cur] < cost) continue;

        for (auto [nxt, w] : adj[cur]) {
            int ncost = cost + w;
            if (dist[nxt] > ncost) {
                dist[nxt] = ncost;
                pq.push({ncost, nxt});
            }
        }
    }

    // dist[i] : start에서 i까지 최단 거리
    return 0;
}
