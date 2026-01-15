// BOJ 16401. 과자 나눠주기 / S2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, N;
	cin >> M >> N;

	vector<int> snack(N);
	for (int i = 0; i < N; i++) {
		cin >> snack[i];
	}

	int s = 1;
	int b = *max_element(snack.begin(), snack.end());
	int ans = 0;
	while (s <= b) {
		int L = (s + b) / 2;
		int total_n = 0;
		for (int len : snack) {
			total_n += len / L;
		}

		if (total_n >= M) {
			s = L+1;
			ans = L;
		}
		else {
			b = L-1;
		}
	}
	cout << ans << "\n";
}

/*
과자의 수가 사람의 수보다 많은 경우에는 상관 없지만
과자의 수가 사람의 수보다 적은 경우에는 어떻게 나눌지 문제 발생
이분탐색으로 진행
제일 작을 수 있는 길이는 s -> 초기값은 1
제일 클 수 있는 길이는 b -> 초기값은 과자 중 가장 긴 길이
둘을 더해서 2로 나눈 값을 L로 하고 이분 탐색 진행
과자의 길이 / L은 나눠 줄 수 있는 사람의 수 -> 이걸로 판단
*/