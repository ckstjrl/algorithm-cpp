// SWEA 1219. 길 찾기 / D4
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int T = 10;
	while (T--) {
		int tc, L;
		cin >> tc >> L;

		vector<vector<int>> arr(100);
		while (L--) {
			int s, e;
			cin >> s >> e;
			arr[s].emplace_back(e);
		}

		queue<int> q;
		int visited[100] = { 0 };

		q.push(0);
		visited[0] = 1;

		while (!q.empty()) {
			int a = q.front(); q.pop();
			for (int nxt : arr[a]) {
				if (!visited[nxt]) {
					visited[nxt] = 1;
					q.push(nxt);
				}
			}
		}
		int ans = 0;
		if (visited[99] == 1) ans = 1;

		cout << "#" << tc << ' ' << ans << "\n";
	}
}

/*
자료구조 queue 활용, BFS로 문제 풀이
*/