// BOJ 2660. 회장뽑기 / G5
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1);
    while (1) {
        int a, b;
        cin >> a >> b;
        
        if (a == -1 && b == -1) {
            break;
        }

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> score(N + 1, N + 1);
    for (int i = 1; i < N + 1; i++) {
        queue<int> q;
        vector<int> visited(N + 1, -1);
        q.push(i);
        visited[i] = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int nxt : graph[cur]) {
                if (visited[nxt] == -1) {
                    visited[nxt] = visited[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        score[i] = *max_element(visited.begin(), visited.end());
    }

    int min_s = *min_element(score.begin(), score.end());
    int cnt = count(score.begin(), score.end(), min_s);
    
    cout << min_s << " " << cnt << "\n";
    
    for (int i = 1; i < N + 1; i++) {
        if (score[i] == min_s) {
            cout << i << " ";
        }
    }
}

/*
BFS 활용
가장 먼 친구까지 가는 거리가 결국 해당 사람의 점수가 된다.
for 문으로 모든 사람이 시작이 되는 조건을 잡고 BFS를 진행하여 점수를 구했다.
점수 중에 최솟값과 해당 최솟값을 요소로 갖는 인덱스의 수를 세서 출력
이후 for문으로 순회하며 최솟값을 가진 인덱스를 순서대로 출력
*/