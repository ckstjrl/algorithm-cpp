// SWEA 1210. Ladder1 / D4
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> arr(100, vector<int>(100, 0));
int N = 100;
int two_j;

int ladder(int y, int x) {
	if (y == 0 && arr[y][x] == 1) return x;

	if (arr[y][x - 1] == 1) {
		while (x > 0 && arr[y][x - 1] == 1) {
			x--;
		}
		return ladder(y - 1, x);
	}

	if (arr[y][x + 1] == 1) {
		while (x < N-1 && arr[y][x + 1] == 1) {
			x++;
		}
		return ladder(y - 1, x);
	}

	return ladder(y - 1, x);
}



int main() {
	int T = 10;
	while (T--) {
		int t;
		cin >> t;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		for (int y = 0; y < N; y++) {
			if (arr[99][y] == 2) two_j = y;
		}

		cout << "#" << t << ' ' << ladder(99, two_j) << "\n";
	}
}

/*
처음 일반적인 좌우상 방향을 탐색하는 DFS로 진행했다 오답이 나와서 다시 고민하고 풀이

도착지점인 2 인덱스를 찾아서 거기서 시작함
ladder 함수를 만들어서
행이 0이 되고 arr[y][x]가 1인 지점일 떄 x를 리턴
만약 좌로 가는 방향이 존재한다면 갈 수 있는 만큼 좌로 가고 위로 가는 방향으로 리턴
만약 우로 가는 방향이 존재한다면 갈 수 있는 만큼 우로 가고 위로 가는 방향으로 리턴
좌우 길이 없다면 위로 가는 방향으로 리턴
*/