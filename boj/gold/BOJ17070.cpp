// BOJ 17070. 파이프 옮기기 1 / G5
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> home(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> home[i][j];
        }
    }

    vector<vector<vector<long long>>> dp(N, vector<vector<long long>>(N, vector<long long>(3, 0)));
    dp[0][1][0] = 1;
    
    for (int i = 0; i < N; i++){
        for (int j = 1; j < N; j++) {
            for(int s = 0; s <3; s++) {
                if (dp[i][j][s] == 0 || home[i][j] == 1) continue;
    
                if (s == 0) {
                    if (j + 1 < N && home[i][j + 1] == 0) {
                        dp[i][j + 1][s] += dp[i][j][s];
                    }
                    if (i + 1 < N && j + 1 < N && home[i][j + 1] + home[i + 1][j] + home[i + 1][j + 1] == 0){
                        dp[i + 1][j + 1][s + 2] += dp[i][j][s];
                    }
                }
    
                else if (s == 1) {
                    if (i + 1 < N && home[i + 1][j] == 0) {
                        dp[i + 1][j][s] += dp[i][j][s];
                    }
                    if (i + 1 < N && j + 1 < N && home[i][j + 1] + home[i + 1][j] + home[i + 1][j + 1] == 0){
                        dp[i + 1][j + 1][s + 1] += dp[i][j][s];
                    }
                }
    
                else {
                    if (j + 1 < N && home[i][j + 1] == 0) {
                        dp[i][j + 1][s - 2] += dp[i][j][s];
                    }
                    if (i + 1 < N && home[i + 1][j] == 0) {
                        dp[i + 1][j][s - 1] += dp[i][j][s];
                    }
                    if (i + 1 < N && j + 1 < N && home[i][j + 1] + home[i + 1][j] + home[i + 1][j + 1] == 0){
                        dp[i + 1][j + 1][s] += dp[i][j][s];
                    }
                }
            }
        }
    }

    long long ans = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
    cout << ans << "\n";
}

/*
3차원 dp 활용
상태가 가로, 세로, 대각인 상태에 따라서 판단하여 이동
가로로 이동할 경우 [i][j + 1] 이 벽이 아니여야 하고
세로로 이동할 경우 [i + 1][j] 이 벽이 아니여야 하고
대각으로 이동할 경우 [i][j + 1], [i + 1][j], [i + 1][j + 1]이 벽이 아니여야 한다.

가로 세로 이동의 경우 일반적으로 조건을 확인했지만
대각의 경우 모두 조건으로 작성할 경우 가독성이 낮아질 것을 고려해 3칸 중 하나라도 1이면 안되기 때문에 3칸의 합이 0일 떄만 이동한다 조건 작성
*/