// BOJ 2711. 오타맨 고창영 / B2

#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		string s;
		cin >> n >> s;
		s.erase(n - 1, 1);
		cout << s << '\n';
	}
}

/*
테스트 케이스를 T로 받고 for문으로 반복
오타낸 위치를 n으로 받고 문자열은 s로 받음
s.erase(지우기 시작할 인덱스, 지울 문자 개수) 함수 활용하여
지울 문자를 지운 후 문자열 출력
*/