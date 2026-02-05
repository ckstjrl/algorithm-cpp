// BOJ 1920. 수 찾기 / S4
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;

	vector<long long> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		long long check;
		cin >> check;


		int l = 0;
		int r = N - 1;
		int ans = 0;
		while (l <= r) {
			int mid = (r + l) / 2;
			if (num[mid] == check) {
				ans = 1;
				break;
			}
			else if (num[mid] < check) {
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}

		cout << ans << "\n";
	}
}

/*
숫자를 정렬한 후 이분탐색 진행
*/