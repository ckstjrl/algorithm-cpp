// BOJ 2096. 내려가기 / G5
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> dp(3), temp(3);

    for (int i = 0; i < 3; i++) {
        int a;
        cin >> a;
        dp[i] = { a, a };
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            int a;
            cin >> a;
            if (j == 0) {
                temp[0].first = a + max(dp[0].first, dp[1].first);
                temp[0].second = a + min(dp[0].second, dp[1].second);
            }

            else if (j == 2) {
                temp[2].first = a + max(dp[2].first, dp[1].first);
                temp[2].second = a + min(dp[2].second, dp[1].second);
            }

            else {
                temp[1].first = a + max(dp[1].first, max(dp[0].first, dp[2].first));
                temp[1].second = a + min(dp[1].second, min(dp[0].second, dp[2].second));
            }
        }
        dp = temp;
    }

    int max_v = max(dp[0].first, max(dp[1].first, dp[2].first));
    int min_v = min(dp[0].second, min(dp[1].second, dp[2].second));
    
    cout << max_v << " " << min_v << "\n";
}

/*
dp 활용
처음에 dp 배열을 전부 작성한 경우 메모리 초과 발생
dp와 temp 배열로 두고
temp 배열에 최신화 한 이후 dp 배열에 넣어주는 방식으로 진행
최솟값과 최댓값을 동시에 구해야 하기때문에 pair 형식을 활용해서 first에는 최댓값, second에는 최솟값을 넣는 방식으로 풀이 진행
*/