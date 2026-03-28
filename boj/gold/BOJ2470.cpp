// BOJ 2470. 두 용액 / G5
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> liq;
long long diff = 2e9 + 1;
int ansl, ansr;

void sol(int N) {
    int l = 0;
    int r = N - 1;
    while (l < r) {
        long long d = liq[l] + liq[r];
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

    sort(liq.begin(), liq.end());

    sol(N);

    cout << liq[ansl] << " " << liq[ansr] << "\n";
}