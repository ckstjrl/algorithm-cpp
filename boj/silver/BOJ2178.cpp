// BOJ 2178. 미로 탐색 / S1
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> miro(N + 2, vector<int>(M + 2, 0));

	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= M; j++) {
			miro[i][j] = s[j - 1] - '0';
		}
	}

	queue<pair<int, int>> q;
	vector<vector<int>> visited(N + 2, vector<int>(M + 2, 0));

	int di[4] = {1, -1, 0, 0};
	int dj[4] = {0, 0, 1, -1};

	q.push({1, 1});
	visited[1][1] = 1;

	while (!q.empty()) {
		auto [i, j] = q.front();
		if (i == N && j == M) break;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ni = i + di[d];
			int nj = j + dj[d];
				
			if (miro[ni][nj] == 0 || visited[ni][nj] != 0) continue;

			q.push({ni, nj});
			visited[ni][nj] = visited[i][j] + 1;
			
		}
	}
	cout << visited[N][M] << "\n";
}

/*
이차원 벡터에 miro를 집어 넣음, input이 붙어 있기 때문에 string으로 받고 넣어줘야함
이후 queue를 활용해서 bfs 탐색 진행
탐색하면서 visited를 몇번째 방문한건지 확인하기 위해
이전 visited + 1을 진행함
마지막에 visited[N][M]을 출력하면 총 몇 칸 움직였는지 확인 가능
*/