// SWEA 1226. 미로1 / D4
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	int T = 10;
	while (T--) {
		int tc;
		cin >> tc;

		int miro[16][16] = { 0 };
		for (int i = 0; i < 16; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 16; j++) {
				miro[i][j] = s[j] - '0';
			}
		}

		int si, sj, ei, ej;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				if (miro[i][j] == 2) {
					si = i;
					sj = j;
				}
				if (miro[i][j] == 3) {
					ei = i;
					ej = j;
				}
			}
		}

		queue<pair<int, int>> q;
		int visited[16][16] = { 0 };
		int di[4] = { 1, -1, 0, 0 };
		int dj[4] = { 0, 0, 1, -1 };

		q.push({ si, sj });
		visited[si][sj] = 1;

		int ans = 0;
		while (!q.empty()) {
			int ci = q.front().first;
            int cj = q.front().second;
			if (ci == ei && cj == ej) {
				ans = 1;
				break;
			}
			q.pop();

			for (int d = 0; d < 4; d++) {
				int ni = ci + di[d];
				int nj = cj + dj[d];

				if (0 <= ni && ni < 16 && 0 <= nj && nj < 16){
					if (miro[ni][nj] != 1 && visited[ni][nj] != 1) {
						q.push({ ni, nj });
						visited[ni][nj] = 1;
					}
				}
			}
		}

		cout << "#" << tc << ' ' << ans << "\n";
	}
}

/*
알고리즘 BFS 사용

SWEA 제출 프로그램이 C++14를 활용하여
auto [ci, cj] = q.front();
를 활용 할 수 없어

int ci = q.front().first;
int cj = q.front().second;
활용함
*/