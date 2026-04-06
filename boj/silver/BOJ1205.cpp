// BOJ 1205. 등수 구하기 / S4
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P;
    long long S;
    cin >> N >> S >> P;

    if (N == 0) {
        cout << 1 << "\n";
        return 0;
    }

    vector<long long> ranks;
    for (int i = 0; i < N; i++) {
        int score;
        cin >> score;
        ranks.push_back(score);
    }

    if (N == P && ranks[N - 1] >= S) {
        cout << -1 << "\n";
        return 0;
    }

    int rank = 1;
    for (int r : ranks) {
        if (r > S) rank++;
        else break;
    }

    cout << rank << "\n";
}

/*
구현
N == 0인 경우 무조건 1등
N == P이고 마지막 요소가 S와 동일하거나 큰 경우 -1
이 외의 경우에서는 ranks의 요소 크기가 S보다 크다면 rank + 1
아닌 경우 rank 출력
*/