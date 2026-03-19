// BOJ 11047. 동전 0 / S4
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> coins(N);
    for (int i = N - 1; i >= 0; i--) {
        cin >> coins[i];
    }

    int ans = 0;
    for (int i = 0 ; i < N; i++) {
        if (coins[i] > K) continue;

        if (K == 0) break;

        ans += K / coins[i];
        K = K % coins[i];
    }
    cout << ans << "\n";
}

/*
동전이 오름차순으로 나오는데 필요한 배열은 내림차순이므로 벡터에 거꾸로 담음
큰 동전부터 순회하면서 K를 동전으로 나눈 값을 ans에 더해주고 나눈 나머지로 K를 최신화 해주는 방식으로
K가 0이 될때까지 진행
*/