// BOJ 11050. 이항 계수 1 / B1
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	if (K == 0 || K == N) {
		cout << 1 << "\n";
	}
	else {
		int a = 1;
		for (int i = 2; i <= N; i++) {
			a *= i;
		}
		int b = 1;
		for (int i = 1; i <= K; i++) {
			b *= i;
		}
		int c = 1;
		for (int i = 1; i <= (N - K); i++) {
			c *= i;
		}

		cout << a / (b * c) << "\n";
	}
}

/*
이항 계수 문제의 경우 여러가지 방법이 존재할 것으로 생각됨.
1. 피보나치 수열 사용
2. 조합 함수 활용
3. nCk 구현
이 3가지 방법 중 3번 방법으로 진행
*/