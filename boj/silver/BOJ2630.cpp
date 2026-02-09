// BOJ 2630. 색종이 만들기 / S2
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;
int white = 0;
int blue = 0;

void solve(int x, int y, int size) {
    int start = paper[x][y];
    bool same = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (start != paper[i][j]) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        if (start == 0) white++;
        else blue ++;
        return;
    }

    int half = size / 2;
    solve(x, y, half);
    solve(x + half, y, half);
    solve(x, y + half, half);
    solve(x + half, y + half, half);
}

int main() {
    int N;
    cin >> N;

    paper.assign(N, vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    cout << white << "\n" << blue << "\n";
}

/*
분할정복, 재귀 활용
색이 동일하다면 해당 색의 count를 올리고
색이 동일하지 않다면 재귀를 통해서 4분할 진행
*/