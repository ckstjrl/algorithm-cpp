// BOJ 5598. 카이사르 암호 / B2
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if ((int)s[i] < 68) {
			s[i] = (int)s[i] + 26;
		}
		s[i] = (int)s[i] - 3;
	}
	cout << s;
}

/*
알파벳 아스키 코드 활용
A, B, C의 경우 -3을 하면 알파벳이 아니게 되므로, +26을 하면 규칙에 맞음
이외 알파벳은 -3을 진행하면 됨.
연산을 위해 (int)s[i]로 형변환 해서 진행
*/