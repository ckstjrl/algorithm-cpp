// BOJ 9095. 1, 2, 3 더하기 / S3
#include <iostream>

using namespace std;

long long dp[12];

int main() {
	int T;
	cin >> T;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 12; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	while (T--) {
		int N;
		cin >> N;
		
		cout << dp[N] << "\n";
	}
}

/*
11까지만 원하기 때문에 dp[12]를 미리 전역 변수에 선언
dp[1], dp[2], dp[3]을 미리 구하고 다이나믹프로그래밍 진행
혹시라도 dp[11]이 int 범위를 넘을 수도 있어서 long long으로 선언
이후 N을 받아 출력
*/