// PGS 12914. 멀리뛰기 / Lv.2
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long dp[2001];
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }
    
    return dp[n];
}

/*
dp 활용
n으로 갈 수 있는 방법은 n - 1지점에서 1칸 뛰기 또는 n - 2지점에서 2칸 뛰기이므로 점화식 구함
*/