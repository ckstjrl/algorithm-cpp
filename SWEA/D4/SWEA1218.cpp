// SWEA 1218. 괄호 짝짓기 / D4
#include <iostream>
#include <stack>

using namespace std;

int main() {
	int T = 10;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;

		int ans = 1;
		stack<char> check;
		while (N--) {
			char s;
			cin >> s;

			if (s == '(' || s == '{' || s == '[' || s == '<') check.push(s);
			else {
				if (check.empty()) {
					ans = 0;
				}
				else {
					char top = check.top();
					if (s == ')' && top == '(' ||
						s == '}' && top == '{' ||
						s == ']' && top == '[' ||
						s == '>' && top == '<') {
						check.pop();
					}
					else {
						ans = 0;
					}
				}
			}
		}

		if (!check.empty()) ans = 0;
		
		cout << "#" << tc << ' ' << ans << "\n";
	}
}

/*
자료구조 stack 활용
ans를 기본으로 1로 설정해 놓고
열리는 괄호의 경우 stack에 집어 넣고
닫히는 괄호의 경우 stack의 top과 비교한후 짝이 맞으면 pop
짝이 맞지 않으면 ans를 0으로 변환
총 루프를 돌고 stack이 비어있지 않으면 ans를 0으로 변환
이후 ans 출력
*/