// BOJ 9465. 스티커 / S1
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<vector<int>> stick(2, vector<int>(N, 0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                cin >> stick[i][j];
            }
        }
        
        if (N == 1) {
            cout << max(stick[0][0], stick[1][0]) << "\n";
            continue;
        }

        vector<vector<int>> dp(2, vector<int>(N, 0));
        dp[0][0] = stick[0][0];
        dp[1][0] = stick[1][0];
        dp[0][1] = stick[0][1] + dp[1][0];
        dp[1][1] = stick[1][1] + dp[0][0];
        for (int j = 2; j < N; j++) {
            dp[0][j] = stick[0][j] + max(dp[1][j - 1], dp[1][j - 2]);
            dp[1][j] = stick[1][j] + max(dp[0][j - 1], dp[0][j - 2]);
        }
        
        cout << max(dp[0][N - 1], dp[1][N - 1]) << "\n";
    }
}

/*
초반에는 그리디, 재귀 활용해서 문제 풀이 진행 -> 코드 로직이 복잡해지고 이상해짐
최종적으로 DP활용해서 문제 풀이 진행
*/