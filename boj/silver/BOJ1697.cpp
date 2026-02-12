// BOJ 16897. 숨바꼭질 / S1
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    const int MAX = 100000;
    vector<int> dist(MAX + 1, -1);

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

        int nxt[3] = {cur - 1, cur + 1, cur * 2};

        for(int n :  nxt){
            if (0 <= n && n <= MAX) {
                if (dist[n] == -1) {
                    dist[n] = dist[cur] + 1;
                    q.push(n);
                }
            }
        }
    }
}

/*
BFS활용
수빈이가 갈 수 있는 위치가 3가지 이므로 이 3가지를 돌면서 확인하는 과정을 통해
K로 갈 수 있는 방법을 찾고 그 횟수를 출력
*/