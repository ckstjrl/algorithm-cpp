// BOJ 1351. 무한 수열 / G5
#include <iostream>
#include <unordered_map>

using namespace std;
long long N, P, Q;
unordered_map<long long, long long> dp;

long long A(long long x) {
    if (dp.find(x) != dp.end()) {
        return dp[x];
    }

    dp[x] = A(x / P) + A(x / Q);
    return dp[x];
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> P >> Q;
    dp[0] = 1;

    cout << A(N) << "\n";
}

/*
unordered_map 자료구조 활용
Ai의 경우 key i에 value로 설정하는 방식으로 dp 구현
배열 dp로 풀이하게되면 시간복잡도 메모리 초과
재귀함수를 통해서 dp에 x가 존재하는지 하지 않는지 확인하여 구현
*/