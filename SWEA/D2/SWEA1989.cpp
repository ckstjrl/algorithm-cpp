// SWEA 1989. 초심자의 회문 검사 / D2
#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		string s;
		cin >> s;

		int l = s.length();
		int ans = 1;
		for (int i = 0; i < l / 2; i++) {
			if (s[i] != s[l - i - 1]) {
				ans = 0;
				break;
			}
		}

		cout << "#" << tc << ' ' << ans << "\n";
	}
}

/*
string의 인덱스를 활용하여
앞과 뒤가 동일한지 확인하고 그게 아니면 ans=0으로 변경하여 출력
*/