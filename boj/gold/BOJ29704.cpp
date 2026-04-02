// BOJ 29704. 벼락치기 / G5
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;

    vector<int> dp(T + 1, 0);
    int total = 0;

    for (int i = 0; i < N; i++) {
        int d, m;
        cin >> d >> m;
        total += m;

        for (int t = T; t >= d; t--) {
            dp[t] = max(dp[t], dp[t - d] + m);
        }
    }

    int saved = 0;
    for (int t = 0; t <= T; t++) {
        saved = max(saved, dp[t]);
    }

    cout << total - saved << '\n';
    return 0;
}

/*
dp 활용
앞에서 부터 갱신하면 같은 과제를 여러번 푸는 것 처럼 되기 떄문에 뒤에서 부터 갱신
*/