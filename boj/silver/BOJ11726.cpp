// BOJ 11726. 2xn 타일링 / S3
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dp(N + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    if (N > 2) {
        for (int i = 3; i < N + 1; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
        }
    }
    cout << dp[N] << "\n";
}

/*
다이나밋 프로그래밍 활용
점화식을 구해서 배열 완성 후 해당 인덱스 출력
*/