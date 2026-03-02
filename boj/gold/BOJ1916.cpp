// BOJ 1916. 최소비용 구하기 / G5
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 200000000;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int M;
    cin >> M;

    vector<vector<pair<int, int>>> adj(N + 1);
    vector<int> dist(N + 1, INF);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({ v, w });
    }

    int start, end;
    cin >> start >> end;
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (pair<int, int> nxtpair : adj[cur]) {
            int ncost = dist[cur] + nxtpair.second;
            int nxt = nxtpair.first;

            if (ncost < dist[nxt]) {
                dist[nxt] = ncost;
                pq.push({ ncost, nxt });
            }
        }
    }

    cout << dist[end] << "\n";
}

/*
다익스트라 활용
*/