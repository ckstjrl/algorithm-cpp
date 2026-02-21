// BOJ 1931. 회의실 배정 / G5
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> time;
    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        time.push_back({ s, e });
    }

    sort(time.begin(), time.end(), [](pair<int, int> a, pair<int, int> b){
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    int cnt = 1;
    int s = time[0].first;
    int e = time[0].second;
    for (int i = 1; i < N; i++) {
        if (time[i].first >= e){
            s = time[i].first;
            e = time[i].second;
            cnt++;
        }
    }

    cout << cnt << "\n";
}

/*
pair의 second를 사용하여 오름차순 정렬 진행하여 문제 풀이
종료 시간이 빠를 수록 뒤에 올 수 있는 회의가 더 많다는 점을 활용하여 답 출력

sort(time.begin(), time.end(), [](pair<int, int> a, pair<int, int> b){
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
});

second를 기준으로 오름차순 정렬 후 만약 두 값이 동일하다면 first를 기준으로 정렬하는 식
*/