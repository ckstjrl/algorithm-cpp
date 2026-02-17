// PGS 12980. 점프와 순간 이동 / Lv.2
#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 1;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n--;
            ans++;
        }
    }
    return ans;
}

// DP 활용했지만, 효율성 검사에서 메모리 초과 시간초과 발생
/*
#include <iostream>
#include <vector>
using namespace std;

int solution(int n)
{
    int ans = 0;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        if (i % 2 == 0) {
            dp[i] = dp[i / 2];
        }
        else {
            dp[i] = dp[i - 1] + 1;
        }
    }
    ans = dp[n];
    return ans;
}
*/

/*
처음에는 DP로 풀이를 진행했지만, N의 크기가 최대 10억이기 때문에 메모리 초과, 시간 초과 발생
DP를 채워나가는 방법을 거꾸로 생각해서 N을 1로 만드는 방법으로 문제 풀이
2로 나누는 것은 배터리 소모 X
2로 나누어 떨어지지 않는 경우 -1 진행할 때는 배터리 소모 1
이렇게 로직을 생각하고 진행
*/