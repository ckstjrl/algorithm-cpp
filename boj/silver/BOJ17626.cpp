// BOJ 17626. Four Squares / S2
#include <iostream>
#include <vector>

using namespace std;

int sqr[708] = { 0 };
int main() {
	for (int i = 1; i < 708; i++) {
		sqr[i] = i * i;
	}
	int N;
	cin >> N;
	vector<int> dp(500001, 0);
	for (int idx : sqr) {
		dp[idx] = 1;
	}
	for (int i = 1; i <= N; i++) {
		int min_v = 5;
		if (dp[i] == 1) continue;

		if (i % 2 == 0) {
			int d = i / 2;
			for (int j = 0; j < d; j++) {
				int v = dp[d - j] + dp[d + j];
				if (v < min_v) {
					min_v = v;
				}
				if (v == 2) {
					min_v = 2;
					break;
				}
			}
			dp[i] = min_v;
		}

		else {
			int d = i / 2;
			for (int j = 0; j < d; j++) {
				int v = dp[d - j] + dp[d + 1 + j];
				if (v < min_v) {
					min_v = v;
				}
				if (v == 2) {
					min_v = 2;
					break;
				}
			}
			dp[i] = min_v;
		}
	}
	cout << dp[N] << "\n";
}

/*
다이나믹 프로그래밍 + 브루드포스 알고리즘 활용

처음에는 가장 가까운 제곱 수를 0이 될 때까지 while 반복문을 통해 연산하며 while구문이 반복된 횟수를 답이라 생각
-> 22같은 경우에 16으로 빼서 구하는 방법보다 9+13 이 더 빠르다는 반례 존재

다이나믹 프로그래밍을 작성하기 위해 점화식을 구하는데 따로 점화식이 존재하지 않음
여기서 C라는 숫자를 A+B로 만들고 A의 값 + B의 값을 더한 것의 최소값을 해당 숫자의 정답으로 생각

먼저 제곱하여 만들 수 있는 숫자들을 배열에 넣어주고 (N <= 500000 이므로 707까지만 제곱하면 됨)
dp 배열에 해당 숫자 인덱스에는 1을 미리 넣어줌

min_v = 5로 설정한 이유는 모든 숫자는 4개의 제곱 수로 만들수 있다는 전제가 있기 때문.
dp를 만드는 과정에서도 1이 있으면 넘어가게 만들고
짝수의 경우 반으로 나누어 한쪽은 -1씩 한쪽은 +1씩 하는 방법으로 탐색진행 -> min_v를 조건에 맞으면 최신화 / 만약 2가 된다면 더이상 작은 수는 없기 때문에 break
홀수의 경우 반으로 나누어 한쪽에 +1을 해준 상태로 한쪽은 -1씩 한쪽은 +1씩 하는 방법으로 탐색진행 -> min_v를 조건에 맞으면 최신화 / 만약 2가 된다면 더이상 작은 수는 없기 때문에 break
최종적으로 for문 종료 후 min_v를 dp배열에 넣어줌
해당 과정을 통해 dp 완성
*/