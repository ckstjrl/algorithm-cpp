/*BOJ 10162. 전자레인지 / B3*/

#include <iostream>

using namespace std;
int main(void) {
	int T;
	cin >> T;

	int A = T / (60 * 5);
	T %= (60 * 5);

	int B = T / 60;
	T %= 60;

	int C = T / 10;
	T %= 10;

	if (0 == T) {
		cout << A << " " << B << " " << C;
	}
	else {
		cout << -1;
	}
}

/*
전체 시간 T를 int로 받고 5분, 1분, 10초 시간으로 나누고 T를 나머지로 갱신
최종적으로 모든 과정 후 T가 0이면 A B C를 출력하고
0이 아니라면 -1을 출력하게 문제풀이
*/