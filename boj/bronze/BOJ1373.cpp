// BOJ 1373. 2진수 8진수 / B1

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	string bi;
	cin >> bi;
	int n = 3 - bi.length() % 3;
	if (n != 3) {
		while (n--) bi.insert(0, "0");
	}
	
	int l = bi.length() / 3;

	vector<int> oct(l);
	for (int i = 0; i < l; i++) {
		oct[i] = (bi[3 * i + 2]-'0') + (bi[3 * i + 1]-'0') * 2 + (bi[3 * i]-'0') * 4;
	}
	for (int i = 0; i < oct.size(); i++) {
		cout << oct[i];
	}
}

// 0000 이라면 00이 출력되어야 하는데 그걸 생각 안하고 한 풀이
/*
int main() {
	vector<int> oct;

	string b;
	cin >> b;

	long long de = 0;

	for (int i = 0; i < b.length(); i++) {
		de += (b[i]-'0') * pow(2, b.length() - i - 1);
	}

	if (de == 0) {
		oct.emplace_back(0);
	}

	while (de) {
		oct.emplace_back(de % 8);
		de /= 8;
	}

	for (int i = oct.size() - 1; i >= 0; i--) {
		cout << oct[i];
	}
}
*/


/*
처음엔 2진수를 10진수로 변환한 후 8진수로 변환하는 풀이 진행
여기서 2진수가 0000일때 정답이 00인데 위 풀이로 풀면 0만 출력되는 오류 발생

2진수를 3개씩 끊어 8진수로 연산하여 출력하는 방식 활용
입력을 string으로 받고
string의 길이가 3의 배수가 아닌 경우 3의 배수가 될 수 있게 0을 앞쪽에 추가해줌
이후 string의 길이를 3으로 나눈 수 만큼 반복하며
2진수를 8진수로 변경하여 vector에 넣어줌
이후 vector을 순회하며 출력해주는 방식 활용
*/