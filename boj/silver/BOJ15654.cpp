// BOJ 15654. N과 M (5) / S3
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> num;
vector<int> visited;
vector<int> arr;

void sol(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            arr[depth] = num[i];
            sol(depth + 1);
            visited[i] = 0;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    num.resize(N);
    visited.assign(N, 0);
    arr.resize(M);
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    sol(0);
}

/*
재귀 함수 활용
visited를 활용해서 중복 방지
*/