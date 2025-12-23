// SWEA 12712. 파리퇴치3 / D2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	int di_t[4] = { 1, -1, 0, 0 };
	int dj_t[4] = { 0, 0, -1, 1 };

	int di_x[4] = { 1, 1, -1, -1 };
	int dj_x[4] = { 1, -1, 1, -1 };

	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		cin >> N >> M;

		vector<vector<int>> fly(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> fly[i][j];
			}
		}
		
		vector<int> kill;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int total_t = fly[i][j];
				int total_x = fly[i][j];
				for (int d = 0; d < 4; d++) {
					for (int m = 1; m < M; m++) {
						int ni = i + di_t[d] * m;
						int nj = j + dj_t[d] * m;
						int ny = i + di_x[d] * m;
						int nx = j + dj_x[d] * m;
						if (ni >= 0 && ni < N && nj >= 0 && nj < N) total_t += fly[ni][nj];
						if (ny >= 0 && ny < N && nx >= 0 && nx < N) total_x += fly[ny][nx];
					}
				}
				kill.emplace_back(total_t);
				kill.emplace_back(total_x);
			}
		}
		int kill_max = *max_element(kill.begin(), kill.end());

		cout << "#" << tc << ' ' << kill_max << "\n";
	}
}

/*
fly 배열의 모든 좌표 (i, j)를 기준으로 탐색
각 좌표에서 두 가지 분사 형태를 계산
    십자(+) 방향
    대각선(X) 방향
각 방향에 대해 m = 1 ~ M-1 만큼 델타 이동하며, 이동한 좌표가 격자 범위 내에 있을 경우에만 파리 수를 누적
십자 형태 합(total_t)과 대각선 형태 합(total_x)을 kill 벡터에 저장
모든 좌표 계산 후 kill 벡터에서 최댓값을 찾아 출력
*/