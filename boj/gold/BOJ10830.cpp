// BOJ 10830. 행렬 제곱 / G4
#include <iostream>
#include <vector>

using namespace std;

int N;

vector<vector<long long>> matrix_multi(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> r(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++){
                r[i][j] = (r[i][j] + a[i][k] * b[k][j]) % 1000;
            }
        }
    }

    return r;
}

vector<vector<long long>> matrix_power(vector<vector<long long>> a, long long b) {
    if (b == 1) {
        return a;
    }

    else if (b % 2 == 0) {
        vector<vector<long long>> half_power = matrix_power(a, b / 2);
        return matrix_multi(half_power, half_power);
    }

    else {
         vector<vector<long long>> half_power = matrix_power(a, (b - 1) / 2);
        return matrix_multi(matrix_multi(half_power, half_power), a);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long B;
    cin >> N >> B;

    vector<vector<long long>> A(N, vector<long long>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<long long>> ans;

    ans = matrix_power (A, B);

    for (vector<long long> v : ans) {
        for (long long i : v) {
            cout << i % 1000 << " ";
        }
        cout << "\n";
    }
}

/*
행렬의 곱, 재귀를 통한 제곱을 활용
행렬의 곱 함수와, 재귀를 통한 제곱 함수를 제작하여 답 출력
행렬의 곱 부분에서 각 요소를 합할 때마다 1000의 나머지를 넣어주는 방식으로 진행하고
추가로 출력할 때 한번 더 1000으로 나눠서 출력함
*/