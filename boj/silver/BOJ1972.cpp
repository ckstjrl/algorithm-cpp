// BOJ 1972. 놀라운 문자열 / S3
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string s;
	while (s != "*") {
		cin >> s;

		if (s == "*") break;

		int l = s.length();
		bool ans = true;

		for (int N = 0; N < l - 1; N++) {
			vector<string> D = {};

			for (int i = 0; i < l - N - 1; i++) {
				string a = "";
				a += s[i];
				a += s[i + N + 1];

				if (find(D.begin(), D.end(), a) != D.end()) {
					ans = false;
					break;
				}

				D.push_back(a);
			}

			if (!ans) break;
		}

		if (ans) cout << s << " is surprising." << "\n";
		else cout << s << " is NOT surprising." << "\n";
	}
}

/*
input을 "*"이 나올 때까지 받고
만약 "*"나왔다면 while문 안에서 break 진행해줘야함. 하지 않을 경우 * uis surprising 출력됨.

l에 s의 길이를 저장하고 활용
첫번째 for문의 경우 D-0부터 D-(l-2)까지 반복하는 것을 의미
N-쌍에서 중복되는 것이 있는지 확인하기 위해 첫번째와 두번째 for문 사이에 vector D를 빈 vector로 선언
두번째 for문의 경우 N-쌍을 직접 구하는 과정
이 과정에서 a가 D에 존재한다면 ans를 false로 바꾸며 break로 반복문 빠져나가고 한번 더 ans를 검사해서 반복문을 완전 빠져나감
a가 D에 존재하지 않는다면 ans는 계속 true로 유지되며 출력 진행
*/