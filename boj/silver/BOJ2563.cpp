// BOJ 2563. 색종이 / S5
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	int board[101][101] = { 0 };

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				board[i][j] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (board[i][j] == 1) {
				cnt += 1;
			}
		}
	}
	cout << cnt;
}

/*
board[101][101]에 전부 0으로 초기화
x, y 값을 받은 후 10 X 10 칸을 1로 변경
이후 board 완전 탐색하며 1의 개수를 count해서 출력
*/
