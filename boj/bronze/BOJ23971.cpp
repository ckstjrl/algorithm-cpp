// BOJ 23971. ZOAC 4 / B3
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N, M;
    cin >> H >> W >> N >> M;

    int garo = H / (N + 1);
    int sero = W / (M + 1);

    if (H % (N + 1) != 0) {
        garo++;
    }
    if (W % (M + 1) != 0) {
        sero++;
    }

    int ans = garo * sero;
    cout << ans << "\n";
}

/*
구현으로 풀이
*/