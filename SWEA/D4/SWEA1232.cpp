// SWEA 1232. 사칙연산 / D4
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

string value[1001];
int left_i[1001];
int right_i[1001];
vector<string> postfix;

void postorder(int node) {
	if (node == 0) return;
	postorder(left_i[node]);
	postorder(right_i[node]);
	postfix.push_back(value[node]);
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int N;
		cin >> N;
		cin.ignore();

		postfix.clear();
		for (int i = 0; i < 1001; i++) {
			value[i].clear();
			left_i[i] = 0;
			right_i[i] = 0;
		}

		for (int i = 0; i < N; i++) {
			string line;
			getline(cin, line);
			stringstream ss(line);

			int idx;
			ss >> idx >> value[idx];
			ss >> left_i[idx];
			ss >> right_i[idx];
		}

		postorder(1);

		stack<long long> s;

		for (string p : postfix) {
			if (p == "+" || p == "-" || p == "*" || p == "/") {
				
				long long b = s.top();
				s.pop();
				long long a = s.top();
				s.pop();

				if (p == "+") s.push(a + b);
				else if (p == "-") s.push(a - b);
				else if (p == "*") s.push(a * b);
				else if (p == "/") s.push(a / b);
			}
			else {
				s.push(stoll(p));
			}
		}
		cout << "#" << tc << ' ' << s.top() << "\n";
	}
}

/*
node 값을 string으로 value 배열에 저장
채우는 방식은 SWEA1231. 중위순회 문제와 동일
후위 순회 방식으로 vector에 후위 표기식 방식으로 저장을 함.
이후 후위 표기식을 계산하는 방식 활용

stoll의 경우 string을 long long으로 타입 변경을 해주는 함수
*/