// SWEA 2001. 파리 퇴치

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "#" << t << ' ';

		int N, M;
		cin >> N >> M;

		vector<vector<int>> fly(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> fly[i][j];
			}
		}

		int max_k = 0;
		for (int y = 0; y <= N - M; y++) {
			for (int x = 0; x <= N - M; x++) {
				int kill = 0;
				for (int i = 0; i < M; i++) {
					for (int j = 0; j < M; j++) {
						kill += fly[y + i][x + j];
					}
				}
				if (kill > max_k) max_k = kill;
			}
		}
		cout << max_k << "\n";
	}
}

/*
kill 변수를 통해서 파리채 크기에 해당하는 vector의 수를 합하고
max_k와 비교한 후 더 크다면 최신화해주는 과정을 통해
최댓값 출력
*/