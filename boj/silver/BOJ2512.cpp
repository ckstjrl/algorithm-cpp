// BOJ 2512 예산 / S2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> budget(N);
	long long sum = 0;
	int max_v = 0;
	for (int i = 0; i < N; i++) {
		cin >> budget[i];
		sum += budget[i];
		if (budget[i] > max_v)max_v = budget[i];
	}

	long long total;
	cin >> total;
	if (total >= sum) {
		cout << max_v << "\n";
	}
	else {
		int l = 0;
		int r = max_v;
		int ans = 0;

		while (l <= r) {
			int m = (l + r) / 2;
			
			long long sum_m = 0;
			for (int b : budget) {
				sum_m += min(b, m);
			}

			if (sum_m <= total) {
				ans = m;
				l = m + 1;
			}
			else if (sum_m > total) {
				r = m - 1;
			}
		}
		cout << ans << "\n";
	}
}

/*
지방 예산을 입력받으면서 배열에 넣음 + 지방 예산 총합 + 최대 지방 예산 한번에 구함
이후 지방 예산 총합이 예산보다 작다면 바로 최대 예산 출력
지방 예산 총합이 예산보다 크다면 이진탐색으로 가장 많이 줄 수 있는 예산의 금액을 찾아서 출력
*/