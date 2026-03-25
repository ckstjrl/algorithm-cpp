// BOJ 10026. 적록색약 / G5
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs(int x, int y, vector<vector<char>>& area, vector<vector<int>>& v, int N) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    v[x][y] = 1;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (v[nx][ny] == 1) continue;
            if (area[nx][ny] != area[cx][cy]) continue;

            v[nx][ny] = 1;
            q.push({ nx, ny });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<char>> rgb(N, vector<char>(N));
    vector<vector<char>> rb(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            rgb[i][j] = s[j];
            
            if (s[j] == 'G') {
                rb[i][j] = 'R';
            }
            else {
                rb[i][j] = s[j];
            }
        }
    }

    vector<vector<int>> visited(N, vector<int>(N, 0));

    int cnt_rgb = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0) {
                bfs(i, j, rgb, visited, N);
                cnt_rgb++;
            }
        }
    }

    visited.assign(N, vector<int>(N, 0));

    int cnt_rb = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 0) {
                bfs(i, j, rb, visited, N);
                cnt_rb++;
            }
        }
    }

    cout << cnt_rgb << " " << cnt_rb << "\n";
}

/*
BFS 활용
BFS를 함수로 제작하고
색약이 없는 사람은 rgb 보드로
색약이 있는 사람은 rb만 있는 보드로 BFS 탐색하여 공간의 개수를 출력
*/