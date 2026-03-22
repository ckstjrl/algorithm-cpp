// BOJ 11444. 피보나치 수 6 / G2
#include <iostream>
#include<vector>

using namespace std;
vector<vector<long long>> FM = { { 1, 1 }, { 1, 0 } };

vector<vector<long long>> matrix_multi(vector<vector<long long>> m, vector<vector<long long>> n) {
    vector<vector<long long>> a(2, vector<long long>(2));
    a[0][0] = (m[0][0] * n[0][0] + m[0][1] * n[1][0]) % 1000000007;
    a[0][1] = (m[0][0] * n[0][1] + m[0][1] * n[1][1]) % 1000000007;
    a[1][0] = (m[1][0] * n[0][0] + m[1][1] * n[1][0]) % 1000000007;
    a[1][1] = (m[1][1] * n[1][1] + m[1][0] * n[0][1]) % 1000000007;

    return a;
}

vector<vector<long long>> matrix_power(vector<vector<long long>> m, long long N) {
    if (N == 0) {
        return { { 1, 0 }, { 0, 1 } };
    }

    if (N == 1) {
        return m;
    }
    
    else if (N % 2 == 0) {
        vector<vector<long long>> half_power = matrix_power(m, N / 2);
        return matrix_multi(half_power, half_power);
    }
    
    else {
        vector<vector<long long>> half_power = matrix_power(m, (N - 1) / 2);
        return matrix_multi(matrix_multi(half_power, half_power), m);
    }

}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    if (n == 0) {
        cout << 0 << "\n";
    }
    else {
        vector<vector<long long>>ans = matrix_power(FM, n);
    
        cout << ans[0][1] << "\n";
    }
}

/*
행렬의 곱을 직접 함수로 작성
피보나치 기본 행렬을 분할 정복을 통한 제곱을 진행하면서 F(n)을 구함
피보나치 기본 행렬을 n번 제곱하면
{{F(n+1), F(n)}
 {F(n), F(n-1)}}
이 형태가 되므로 행렬제곱을 통해 답 출력
*/