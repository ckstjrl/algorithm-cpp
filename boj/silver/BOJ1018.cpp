// BOJ 1018. 체스판 다시 칠하기 / S3
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<vector<int>> board;

int cntwrong(int si, int sj, char sc, char nsc) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char cur;
            if ((i + j) % 2 == 0) {
                cur = sc;
            }
            else cur = nsc;

            if (board[si + i][sj + j] != cur) {
                cnt ++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    board.assign(N, vector<int> (M));
    for (int i = 0; i < N; i++) {
        string r;
        cin >> r;
        for (int j = 0; j < M; j++) {
            board[i][j] = r[j];
        }
    }

    int ans = M * N;
    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++){
            int startW = cntwrong(i, j, 'W', 'B');
            int startB = cntwrong(i, j, 'B', 'W');

            ans = min(ans, min(startW, startB));
        }
    }

    cout << ans << "\n";
}

/*
브루트포스 활용
모든 8*8 영역을 탐색하며 W로 시작, B로 시작 패턴을 비교함
각 영역마다 다시 칠해야 하는 칸 수를 세고 그중 최솟값으로 갱신
전체 최솟값을 출력
*/