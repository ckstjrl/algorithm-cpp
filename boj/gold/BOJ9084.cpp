// BOJ 9084. 동전 / G5
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

        vector<int> coins(N);
        for(int i = 0; i < N; i++) {
            cin >> coins[i];
        }

        int tar;
        cin >> tar;

        vector<long long> kinds(tar + 1, 0);
        kinds[0] = 1;

        for (int coin : coins){
            for (int i = coin; i < tar + 1; i++) {
                kinds[i] += kinds[i - coin];
            }
        }

        cout << kinds[tar] << "\n";
    }
}

/*
dp 활용
점화식을 구해서 문제 풀이
*/