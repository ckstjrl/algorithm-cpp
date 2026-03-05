// BOJ 13549. 숨바꼭질 3 / G5
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> dist(100001, -1);
    queue<int> q;
    q.push(N);
    dist[N] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == K) {
            cout << dist[cur] << "\n";
            break;
        }

        int nxt[3] = { cur * 2, cur - 1, cur + 1 };

        for (int n : nxt) {
            if (0 <= n && n <= 100001) {
                if (dist[n] == -1) {
                    if (n == cur * 2) {
                        dist[n] = dist[cur];
                        q.push(n);
                    }
                    else {
                        dist[n] = dist[cur] + 1;
                        q.push(n);
                    }
                }
            }
        }
    }
}

/*
BFS 활용
queue를 사용할 경우 nxt 배열 만들때 꼭 cur * 2를 먼저 넣어야지 정답이 됨.
-> 2배로 갈 때는 비용 0, 다른 비용은 1이므로 최솟값을 유지하기 위해서는 비용 0인 케이스가 앞으로 가야하기 때문

다른 풀이 방법으로는 
deque을 사용하면 됨
이때 비용이 0인 경우는 push_front
비용이 1인 경우는 push_back을 사용하면 됨
*/