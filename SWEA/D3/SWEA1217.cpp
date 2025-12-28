// SWEA 1217. 거듭 제곱 / D3

#include <iostream>

using namespace std;

int main() {
	int T = 10;
	while (T--) {
		int tc;
		cin >> tc;

		int a, b;
		cin >> a >> b;

		int ans = 1;
		for (int i = 0; i < b; i++) {
			ans *= a;
		}

		cout << "#" << tc << ' ' << ans << "\n";
	}
}

/*
밑 a, 지수 b를 받고
ans를 1로 초기값 설정 후
a를 b번 곱하는 방식으로 거듭제곱을 구함
*/