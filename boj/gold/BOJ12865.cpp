// BOJ 12865. 평범한 배낭 / G5
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> dp(K + 1, 0);
    vector<pair<int, int>> items(N);
    for (int i =0; i < N; i++) {
        int W, V;
        cin >> W >> V;
        items.push_back({ W, V });
    }

    while (!items.empty()) {
        int m = items.back().first;
        int v = items.back().second;
        items.pop_back();

        for (int i = K; i > m - 1; i--) {
            dp[i] = max(dp[i], dp[i - m] + v);
        }
    }

    cout << dp[K] << "\n";
}

/*
dp 활용
저장된 물건 정보를 뽑아 내면서 K부터 해당 물건의 무게까지 dp를 최댓값으로 갱신
*/