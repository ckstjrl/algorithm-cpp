// BOJ 15829. Hashing / B2
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long L;
	cin >> L;

	string s;
	cin >> s;

	long long M = 1234567891;
	long long i = 1;
	long long ans = 0;
	for (char c : s) {
		ans = (ans + ((c - 'a' + 1) * i)) % M;
		i = (i * 31LL) % M;
	}
	cout << ans << "\n";
}


/*  50 점
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long L;
	cin >> L;

	string s;
	cin >> s;

	long long M = 1234567891;
	long long i = 1;
	long long ans = 0;
	for (char c : s) {
		ans += (c - 'a' + 1) * i;
		i *= 31;
		ans %= M;
	}
	cout << ans << "\n";
}

이 경우 ans가 long long의 범위를 넘거나 i가 long long의 범위를 넘는 현상 발생
*/

/*
pow를 쓸 경우 시간 초과 발생할 확률이 높다고 생각하여
i = 1로 초기값을 설정한 후 for문이 종료될 때마다 31을 곱해주는 과정을 거침
ans와 i가 long long의 범위를 초과하는 문제를 해결하기위해
더해주면 M으로 나눈 나머지로 곱해주면 M으로 나눈 나머지로 계속 최신화해줌
*/
