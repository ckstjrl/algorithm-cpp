// BOJ 1780. 종이의 개수 / S2
#include <iostream>

using namespace std;

int n;
int paper[2187][2187];
int cntMinus = 0, cntZero = 0, cntPlus = 0;

void solved(int x, int y, int size) {
    int first = paper[x][y];
    bool same = true;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != first) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        if (first == -1) cntMinus++;
        else if (first == 0) cntZero++;
        else cntPlus++;
        return;
    }

    int newSize = size / 3;
    for (int dx = 0; dx < 3; dx++) {
        for (int dy = 0; dy < 3; dy++) {
            solved(x + dx * newSize, y + dy * newSize, newSize);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    solved(0, 0, n);

    cout << cntMinus << '\n';
    cout << cntZero << '\n';
    cout << cntPlus << '\n';
}

/*
solved 함수 제작
시작 좌표와 사이즈를 입력으로 받고
같은 숫자인지 확인
모두 같은 숫자인 경우에는 해당 숫자의 cnt를 증가
다른 숫자인 경우 9등분 한 후 9등분한 각 시작점을 다시 재귀로 호출
*/