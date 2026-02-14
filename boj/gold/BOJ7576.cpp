// BOJ 7576. 토마토 / G5
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> tomato(N, vector<int>(M));
    queue<pair<int, int>> welltomato;
    int cnt_nowell = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato[i][j];
            
            if (tomato[i][j] == 1) {
                welltomato.push({ i, j });
            }
            
            else if (tomato[i][j] == 0) {
                cnt_nowell++;
            }
        }
    }

    if (welltomato.empty()) {
        cout << -1 << "\n";
    }

    else if (cnt_nowell == 0) {
        cout << 0 << "\n";
    }

    else{
        int welling = 0;
        while (!welltomato.empty()) {
            int x = welltomato.front().first;
            int y = welltomato.front().second;
            welltomato.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                if (0 <= nx && nx < N && 0 <= ny && ny < M && tomato[nx][ny] == 0) {
                    tomato[nx][ny] = tomato[x][y] + 1;
                    welltomato.push({ nx, ny });
                    welling++;
                }

            }
        }

        if (welling < cnt_nowell){
            cout << -1 << "\n";
        }

        else {
            int ans = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j ++) {
                    if (tomato[i][j] > ans){
                        ans = tomato[i][j] - 1;
                    }
                }
            }
            cout << ans << "\n";
        }
    }
}

/*
BFS 활용
일단 토마토 상자를 input으로 받을 때 덜익은 토마토의 개수와 익은 토마토의 좌표를 같이 저장
익은 토마토가 없다면 -1 출력
덜익은 토마토가 없다면 0 출력
둘다 아닐 경우 BFS 진행함 -> 진행하면서 토마토 저장 이차원 배열에 최신화를 진행 + 익혀진 토마토 개수 count
익혀진 토마토 개수와 덜익은 토마토 개수가 다르다면 -1 출력
같다면 토마토 이차원 배열에서 가장 큰 수 -1 을 답으로 출력
*/