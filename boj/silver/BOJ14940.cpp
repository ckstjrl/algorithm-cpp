// BOJ 14940. 쉬운 최단거리 / S1
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int di[4] = { 0, 0, 1, -1 };
int dj[4] = { 1, -1, 0, 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> jido(N, vector<int>(M));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    int si, sj;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> jido[i][j];
            if (jido[i][j] == 2) {
                si = i;
                sj = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({ si, sj });
    jido[si][sj] = 0;
    visited[si][sj] = 1;

    while (!q.empty()) {
        int ci = q.front().first;
        int cj = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int ni = ci + di[d];
            int nj = cj + dj[d];

            if (0 <= ni && ni < N && 0 <= nj && nj < M && jido[ni][nj] == 1 && visited[ni][nj] == 0) {
                jido[ni][nj] = jido[ci][cj] + 1;
                visited[ni][nj] = 1;
                q.push({ ni, nj });
                
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (jido[i][j] != 0 && visited[i][j] == 0){
                cout << -1 << " ";
            }
            else {
                cout << jido[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

/*
BFS 활용
문제와 다르게 2를 목표지점으로 보지 않고 시작지점으로 보고 2에서 시작해서 1인 점들에 도착할 수 있는 방법 찾기
visited에 경로 저장
만약 지도에서 1로 되어있지만 0으로 막혀서 가지 못한 곳은 따로 -1로 출력하고 나머지는 visited 값을 출력
*/