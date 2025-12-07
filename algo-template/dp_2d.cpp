#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> tri(N, vector<int>(N, 0));
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> tri[i][j];
        }
    }

    dp[0][0] = tri[0][0];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            int from_left = (j > 0) ? dp[i - 1][j - 1] : 0;
            int from_right = (j < i) ? dp[i - 1][j] : 0;
            dp[i][j] = max(from_left, from_right) + tri[i][j];
        }
    }

    int ans = 0;
    for (int j = 0; j < N; j++) {
        ans = max(ans, dp[N - 1][j]);
    }

    cout << ans << "\n";
    return 0;
}
