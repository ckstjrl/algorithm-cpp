// SWEA 1222. 계산기1 / D4
// SWEA 1223. 계산기2 / D4
// SWEA 1224. 계산기3 / D4
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int T = 10;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		string postfix = "";
		vector<char>infix(N);
		for (int i = 0; i < N; i++) {
			cin >> infix[i];
		}
		stack<char> op;
		for (char i : infix) {
			if ('0' <= i && i <= '9') {
				postfix += i;
			}
			else if (i == '(') {
				op.push(i);
			}
			else if (i == ')') {
				while (!op.empty() && op.top() != '(') {
					postfix += op.top();
					op.pop();
				}
				if (op.top() == '(') op.pop();
			}
			else {
				while (!op.empty() && op.top() != '(') {
					if (op.top() == '*' || op.top() == '/') {
						postfix += op.top();
						op.pop();
					}
					else if ((op.top() == '+' || op.top() == '-') && (i == '+' || i == '-')) {
						postfix += op.top();
						op.pop();
					}
					else break;
				}
				op.push(i);
			}
		}

		while (!op.empty()) {
			postfix += op.top();
			op.pop();
		}

		stack<int> s;

		for (char p : postfix) {
			if ('0' <= p && p <= '9') {
				s.push(p - '0');
			}
			else {
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
			
				if (p == '+') s.push(a + b);
				else if (p == '-') s.push(a - b);
				else if (p == '*') s.push(a * b);
				else if (p == '/') s.push(a / b);
			}
		}

		cout << "#" << tc << ' ' << s.top() << "\n";
	}
}

/*
중위 표기식 -> 후위 표기식
1. 피연산자(0~9)는 그대로 postfix에 출력
2. '(' 는 스택에 push
3. ')' 를 만나면 '(' 가 나올 때까지 스택에서 pop하여 postfix에 출력
4. '(' 를 pop하여 제거한다(출력하지 않음)
5. 연산자 처리: 스택 top이 '*' 또는 '/' 이면 우선순위가 높으므로 pop하여 출력
6. 스택 top이 '+' 또는 '-' 이고, 현재 연산자도 '+' 또는 '-' 이면 같은 우선순위이므로 pop하여 출력
7. 더 이상 pop 조건이 아니면 현재 연산자를 push
8. 입력을 다 처리한 뒤 스택이 빌 때까지 pop하여 postfix에 출력

후위 표기식 계산법
1. 요소의 type이 int인 스택을 만듦
2. postfix에서 한글자씩 확인
3. 숫자이면 '0'을 빼서 int로 변경하고 스택에 push
4. 만약 연산자라면 stack에서 b를 먼저 뽑고 a를 뽑아내서 a + b 형식으로 연산 진행
5. 이후 스택의 top 값이 연산의 결과
*/