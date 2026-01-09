// BOJ 18111. 마인크래프트 / S2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, B;
	cin >> N >> M >> B;
	int A = N * M;
	int max_time = 500 * 500 * 256;

	vector<int> land(A, 0);
	for (int i = 0; i < A; i++) {
		cin >> land[i];
	}

	sort(land.rbegin(), land.rend());

	vector<int> time(257, max_time);
	for (int h = 0; h <= 256; h++) {
		int time_h = 0;
		int block = B;
		for (int i = 0; i < A; i++) {
			if (land[i] < h) {
				if (block >= h - land[i]) {
					block -= h - land[i];
					time_h += h - land[i];
				}
				else {
					time_h = max_time;
					break;
				}
			}
			else if (land[i] > h) {
				block += land[i] - h;
				time_h += 2 * (land[i] - h);
			}
		}
		time[h] = time_h;
	}
	int min_time = 500 * 500 * 256 + 1;
	int min_idx = 256;
	for (int h = 0; h < 257; h++) {
		if (time[h] <= min_time) {
			min_time = time[h];
			min_idx = h;
		}
	}

	cout << min_time << ' ' << min_idx << "\n";
}

/*
일단 땅의 높이를 굳이 이차원으로 받을 필요성이 없어서 일차원으로 받음
이후 내림차순 정렬로 높은 땅을 앞쪽 인덱스로 오게함 -> 완전탐색을 진행할 때 블록이 모자른 경우를 제대로 판단하기 위해 미리 블록 확보 방안
완전탐색을 통하여 가능하다면 걸린 시간을 해당 높이 인덱스에 넣어주고 불가능하다면 최대 걸리는 시간인 500*500*256 값을 넣어줌
이 과정 이후 최소 시간을 찾고 그 시간과 같다면 계속 뒤 인덱스를 최소시간 인덱스로 넣는 방법으로 답 출력
*/