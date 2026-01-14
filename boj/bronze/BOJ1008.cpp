// BOJ 1008. A/B / B5
#include <iostream>

using namespace std;

int main() {
	double A, B;
	cin >> A >> B;

	double ans = A / B;

	cout << fixed;
	cout.precision(9);
	cout << ans << endl;
}

/*
cout << fixed; -> 고정 소수점 방식으로 출력하는 포멧
cout.precision(n); -> fixed 없이 사용할 경우 유효숫자 n자리 의미, fixed와 함께 사용할 경우 소수점 n번째 자리까지를 의미함
*/