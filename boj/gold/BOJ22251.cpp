// BOJ 22251. 빌런 호석 / G5
#include <iostream>
#include <vector>

using namespace std;

int seg[10][7] = { { 1, 1, 1, 1, 1, 1, 0 },
                    { 0, 1, 1, 0, 0, 0, 0 },
                    { 1, 1, 0, 1, 1, 0, 1 },
                    { 1, 1, 1, 1, 0, 0, 1 },
                    { 0, 1, 1, 0, 0, 1, 1 },
                    { 1, 0, 1, 1, 0, 1, 1 },
                    { 1, 0, 1, 1, 1, 1, 1 },
                    { 1, 1, 1, 0, 0, 0, 0 },
                    { 1, 1, 1, 1, 1, 1, 1 },
                    { 1, 1, 1, 1, 0, 1, 1 } };
int cost[10][10];
int N, K, P, X;

void set_cost(int a, int b) {
    int cnt = 0;
    if (a == b) {
        cost[a][b] = 0;
        cost[b][a] = 0;
        return;
    }

    for (int i = 0; i < 7; i++) {
        if (seg[a][i] != seg[b][i]) {
            cnt++;
        }
    }

    cost[a][b] = cnt;
    cost[b][a] = cnt;

    return;
}

vector<int> itov(int x) {
    vector<int> v(K, 0);
    for (int i = K - 1; i >= 0; i--) {
        v[i] = x % 10;
        x /= 10;
    }

    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            set_cost(i, j);
        }
    }

    cin >> N >> K >> P >> X;

    vector<int> curF = itov(X);

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        if (i == X) continue;

        vector<int> num = itov(i);
        int sum = 0;

        for (int j = 0; j < K; j++) {
            sum += cost[num[j]][curF[j]];
        }

        if (0 < sum && sum <= P) {
            ans++;
        }
    }
    
    cout << ans << "\n";
}

/*
완전 탐색 활용
7segment 형태를 배열로 보고 모든 숫자를 색칠된 칸은 1로 아닌 칸은 0으로 표현해줌
cost 이차원 배열을 통해 a라는 숫자에서 b로 갈 때 변화하는 칸 수를 계산해서 넣는 함수 set_cost 제작
입력을 받은 후
int를 각자리 숫자에 맞게 vector로 만드는 함수 itov를 통해 현재 층의 각 자리 숫자를 배열로 만들고
쓸 수 있는 모든 층을 돌면서 변화하는 칸의 수 총 합이 P보다 작은 경우의 개수를 세서 출력
*/