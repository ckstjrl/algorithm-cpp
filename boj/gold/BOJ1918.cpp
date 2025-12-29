// BOJ 1918. 후위 표기식 / G2
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string postfix = "";
	string infix;
	cin >> infix;

	stack<char> op;
	for (char i : infix) {
		if ('A' <= i && i <= 'Z') {
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

	cout << postfix << "\n";
}

/*
중위 표기식 -> 후위 표기식
1. 피연산자(A~Z)는 그대로 postfix에 출력
2. '(' 는 스택에 push
3. ')' 를 만나면 '(' 가 나올 때까지 스택에서 pop하여 postfix에 출력
4. '(' 를 pop하여 제거한다(출력하지 않음)
5. 연산자 처리: 스택 top이 '*' 또는 '/' 이면 우선순위가 높으므로 pop하여 출력
6. 스택 top이 '+' 또는 '-' 이고, 현재 연산자도 '+' 또는 '-' 이면 같은 우선순위이므로 pop하여 출력
7. 더 이상 pop 조건이 아니면 현재 연산자를 push
8. 입력을 다 처리한 뒤 스택이 빌 때까지 pop하여 postfix에 출력
*/