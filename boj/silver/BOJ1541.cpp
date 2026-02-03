// BOJ 1541. 잃어버린 괄호 / S2
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	vector<string> cal;
	string tmp = "";
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '-') {
			tmp += s[i];
		}
		else {
			cal.push_back(tmp);
			tmp = "";
		}
	}
	cal.push_back(tmp);

	int ans = 0;
	bool first = true;
	for (string c : cal) {
		stringstream ss(c);
		string token;
		int sum = 0;
		
		while (getline(ss, token, '+')) {
			sum += stoi(token);
		}
		
		if (first) {
			ans += sum;
			first = false;
		}
		else {
			ans -= sum;
		}
	}

	cout << ans << "\n";
}

/*
최솟값을 가지려면 -가 나왔을 경우 다음 -가 나오기 전까지의 숫자를 괄호로 묶어서 계산하면 됨
1. string s 를 받고 s를 한번 탐색하면서 -가 나오면 벡터에 값을 넣는 방식 활용
2. 벡터에 담긴 숫자들을 sstream으로 +를 기준으로 분기를 나누어주며 token에 값을 넣고 연산
3. 이 연산이 종료되면 바로 이것이 첫번째 값인지 아닌지를 판단하여 연산 진행
*/