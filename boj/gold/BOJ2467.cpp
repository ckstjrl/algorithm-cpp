// BOJ 2467. 용액 / G5
#include <iostream>
#include <vector>

using namespace std;
vector<long long> liq;
long long diff = 2e9 + 1;
int ansl, ansr;

void sol(int N) {
    int l = 0;
    int r = N - 1;
    while (l < r) {
        long long d = liq[r] + liq[l];
        if (abs(diff) > abs(d)) {
            diff = d;
            ansl = l;
            ansr = r;
            if (diff == 0) {
                return;
            }
        }

        else if (d < 0) {
            l++;
        }
        else {
            r--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    liq.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> liq[i];
    }

    sol(N);

    cout << liq[ansl] << " " << liq[ansr] << "\n";
}

/*
이분탐색 활용
차이의 절댓값이 0에 가까울수록 작은것이므로 새로운 용액의 합과 기존 제일 작은 결과를 둘다 절댓값을 사용해서 비교 진행
*/