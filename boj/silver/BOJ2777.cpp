// BOJ 2777. 숫자 놀이 / S2
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		if (N == 1) {
			cout << 1 << "\n";
			continue;
		}

		vector<int> num;
		while (N != 1) {
			int cnt = 0;
			for (int i = 9; i >= 2; i--) {
				while (N % i == 0) {
					num.push_back(i);
					N /= i;
					cnt++;
				}
			}
			if (cnt == 0) break;
		}
		if (N == 1) {
			cout << num.size() << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
}

/*
N이 1일 때는 무조건 한자리 수
이외의 경우에는 9부터 2 순서대로 나누면서 N이 1이 될때까지 나누기 진행
이 로직에서 주의해야할 점은 나누기가 안되는 경우를 확인해야 한다는 점.
cnt를 사용해서 cnt가 0인 경우 나누기가 진행되지 않았다 판단하고 break하여 while문 나옴
이후 값 출력할 때 N이 1인 경우와 아닌경우를 나누어 출력
*/