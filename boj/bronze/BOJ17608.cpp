// BOJ 17608. 막대기 / B2
// 메모리 2412kb, 시간 48ms
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> b(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}

	int max_v = 0;
	int cnt = 0;
	for (int j = N - 1; j >= 0; j--) {
		if (max_v < b[j]) {
			max_v = b[j];
			cnt++;
		}
	}

	cout << cnt << "\n";
}

/*
입력을 받고 vector 뒤에서 부터 max_v로 최댓값을 확인하면서 그 값보다 큰 것만 보인다 생각하면서
최댓값이 최신화될 떄마다 cnt를 증가시켜 보이는 블록 개수를 출력
*/