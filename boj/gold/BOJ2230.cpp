// BOJ 2230. 수 고르기 / G5
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int l = 0;
    int r = 0;

    long long min_d = 1e10;
    while (r < N) {
        long long diff = arr[r] - arr[l];
        if (diff > M) {
            if (min_d > diff) {
                min_d = diff;
            }
            l++;
        }
        else if (diff == M) {
            min_d = M;
            break;
        }
        else {
            r++;
        }
    }

    cout << min_d << "\n";
}

/*
정렬 & 투 포인터 활용
둘의 차이가 M보다 크다면 l을 증가
둘의 차이가 M보다 작다면 r을 증가
둘의 차이가 M과 동일하다면 정답은 바로 M이 되므로 break로 while문 나옴
*/