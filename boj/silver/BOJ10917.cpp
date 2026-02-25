// BOJ 10917. Your life / S2
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> dreamGraph(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dreamGraph[a].push_back(b);
    }

    vector<int> visited(N + 1, -1);
    queue<int> q;
    q.push(1);
    visited[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : dreamGraph[cur]) {
            int step = visited[cur] + 1;
            if (visited[nxt] == -1) {
                visited[nxt] = step;
                q.push(nxt);
            }

            /*
            if (visited[nxt] == -1) {
                visited[nxt] = step;
            }
            else {
                visited[nxt] = min(visited[nxt], step);
            }

            q.push(nxt);
            */
        }
    }

    cout << visited[N] << "\n";
}

/*
BFS 활용
처음 문제 풀이 과정에서 각주 처럼 min으로 최신화 하는 방법을 사용했는데 메모리 초과 발생
min으로 최신화 하지 않아도 되는 이유 -> 방문을 이미 했다면 현재 방문하는 방법보다 짧은 방법으로 방문을 했다는 의미
*/