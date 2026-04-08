// BOJ 2304. 창고 다각형 / S2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> h;
    int max_i = 0;
    int max_h = 0;
    for (int i = 0; i < N; i++) {
        int L, H;
        cin >> L >> H;

        if (H > max_h) {
            max_h = H;
            max_i = L;
        }

        h.push_back({ L, H });
    }

    sort(h.begin(), h.end());
    int e = h[N-1].first;

    vector<int> stick(e + 1, 0);
    for (int i = 0; i < N; i++) {
        int idx = h[i].first;
        int height = h[i].second;

        stick[idx] = height;
    }

    vector<int> roof(e + 1, 0);
    int cur_h_l = 0;

    for (int i = 0; i <= max_i; i++) {
        if (stick[i] == 0) {
            roof[i] = cur_h_l;
        }

        else if (stick[i] >= cur_h_l) {
            cur_h_l = stick[i];
            roof[i] = cur_h_l;
        }

        else {
            roof[i] = cur_h_l;
        }
    }

    int cur_h_r = 0;
    for (int i = e; i > max_i; i--) {
       if (stick[i] == 0) {
            roof[i] = cur_h_r;
        }

        else if (stick[i] >= cur_h_r) {
            cur_h_r = stick[i];
            roof[i] = cur_h_r;
        }

        else {
            roof[i] = cur_h_r;
        }
    }

    int S = 0;
    for (int r : roof) {
        S += r;
    }

    cout << S << "\n";
}

/*
1000개의 인덱스가 최대이지만 시간 복잡도를 줄이기 위해 처음에는 pair 형태로 좌표 크기를 받고
정렬 후 마지막 좌표가 어디인지 확인하여 배열의 범위를 줄이고 풀이 시작
가장 높은 곳을 기준으로 왼쪽에서 시작하는 것과 오른쪽에서 시작하는 두개의 for문을 통하여 문제 풀이
두 for문의 로직이 동일하여 함수화 시켜 작성해도 간결하고 가독성 좋은 코드 나올 수 있을것 같음
*/