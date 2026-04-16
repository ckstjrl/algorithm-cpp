// PGS 12900. 2 x n 타일링 / Lv.2
#include <string>
#include <vector>

using namespace std;

long long MOD = 1000000007;

int solution(int n) {
    vector<int> dp (60001, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 2] % MOD + dp[i - 1] % MOD) % MOD;
    }
    return dp[n];
}

/*
dp의 근본 문제
*/