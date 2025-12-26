// SWEA 5356. 의석이의 세로로 말해요 / D3
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		vector<vector<string>> board(15, vector<string>(15, "."));
		for (int n = 0; n < 5; n++) {
			string s;
			cin >> s;
			for (int i = 0; i < s.length(); i++) {
				board[n][i] = s[i];
			}
		}
		cout << "#" << tc << ' ';
		for (int x = 0; x < 15; x++) {
			for (int y = 0; y < 15; y++) {
				if (board[y][x] == ".") continue;
				cout << board[y][x];
			}
		}
		cout << "\n";
	}
}

/*
처음 이차원 vector를 만들어서 "."으로 초기화 해 놓은 상태로
input을 string으로 받아 각 인덱스에 맞게 이차원 vector에 넣어줌
이후 for문을 통해 열 인덱스 고정 행 인덱스 이동하는 방식으로 세로로 출력
이 과정에서 행마다 저장된 string의 길이가 다르므로 초기값으로 설정한 "."인 경우 출력하지 않는 방법으로 처리함.
*/