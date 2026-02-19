// BOJ 13023. ABCDE / G5
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> f;
vector<int> visited;

int DFS(int a, int cnt) {
    if (cnt == 4) {
        return 1;
    }
    visited[a] = 1;

    for(int nxt : f[a]) {
        if (visited[nxt] == 0) {
            if (DFS(nxt, cnt + 1)) {
                return 1;
            }
        }
    }

    visited[a] = 0;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    f.assign(N, {});
    visited.assign(N, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        f[a].push_back(b);
        f[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (DFS(i, 0) == 1) {
            ans = 1;
            break;
        }
    }

    cout << ans << "\n";
}

/*
5명이 연속으로 나열될 수 있는지를 확인하는 문제
DFS 활용
DFS의 깊이가 4가 되면 return 1을 진행하고, 아니라면 return 0
이를 확인하여 답 출력
*/