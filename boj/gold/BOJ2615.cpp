// BOJ 2615. 오목 / G5
#include <iostream>
#include <vector>

using namespace std;
int board[19][19];
int dx[4] = { 0, 1, 1, -1 };
int dy[4] = { 1, 0, 1, 1 };

bool inboard (int x, int y) {
    return 0 <= x && x < 19 && 0 <= y && y < 19;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 19; i++) {
        for(int j = 0; j < 19; j++) {
            if (board[i][j] == 0) continue;

            int now = board[i][j];
            for (int d = 0; d < 4; d++) {
                int pi = i - dx[d];
                int pj = j - dy[d];

                if (inboard(pi, pj) && board[pi][pj] == now) continue;

                int cnt = 1;
                int ni = i;
                int nj = j;

                while (1) {
                    ni += dx[d];
                    nj += dy[d];

                    if (!inboard(ni, nj) || board[ni][nj] != now) break;
                    cnt++;
                }

                if (cnt == 5) {
                    cout << now << "\n";
                    cout << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            }
        }
    }

    cout << 0 << "\n";
}

/*
처음에 가로, 세로, 우하향, 좌하향 4가지를 함수화 해서 조건을 만족시키는지 확인하는 코드 작성
-> 조건이 너무 복잡해서 코드 다시 작성
가로, 세로, 우하향, 좌하향 4가지를 델타로 보고 코드 작성하고
좌표가 배열 안에 존재하는지 확인해주는 함수 제작
이후 배열을 순회하면서 조건 만족하면 바로 출력 & return 0으로 종료
아닌 경우 0 출력
*/