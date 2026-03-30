// BOJ 1072. 게임 /S3
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long X, Y;
    cin >> X >> Y;

    int Z = (100 * Y) / X;

    if (Z >= 99) {
        cout << -1 << "\n";
        return 0;
    }

    long long l = 0;
    long long r = 1000000000;
    long long ans = -1;

    while (l <= r) {
        long long mid = (l + r) / 2;
        int nz = (100 * (Y + mid)) / (X + mid);

        if (nz > Z) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}

/*
이분탐색 활용
일단 Z가 99인 경우 더 이상 증가할 수 없기 때문에 -1 출력

이후 X의 최댓값인 10억을 r, 0을 l로 하고
이분탐색 진행
mid 값 만큼 게임을 추가 진행했다고 하고 nz가 Z보다 큰지 아닌지를 통해 진행
*/