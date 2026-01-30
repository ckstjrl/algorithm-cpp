// BOJ 28702. FizzBuzz / B1
#include <iostream>
#include <string>

using namespace std;

string outstr(int n) {
	if (n % 3 == 0 && n % 5 == 0) {
		return "FizzBuzz";
	}
	else if (n % 3 == 0 && n % 5 != 0) {
		return "Fizz";
	}
	else if (n % 3 != 0 && n % 5 == 0) {
		return "Buzz";
	}
	else {
		return to_string(n);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int idx;
	string s[3];
	for (int i = 0; i < 3; i++) {
		cin >> s[i];
		if (isdigit(s[i][0])) {
			N = stoi(s[i]);
			idx = i;
			break;
		}
	}

	if (idx == 0) {
		cout << outstr(N + 3) << "\n";
	}
	else if (idx == 1) {
		cout << outstr(N + 2) << "\n";
	}
	else {
		cout << outstr(N + 1) << "\n";
	}	
}

/*
모든 경우의 수를 확인했을 때 숫자가 나오지 않는 case는 존재하지 않음
숫자가 몇번째에 나오는지 확인하고 그 숫자만 파악한다면 바로 나올 숫자에 대한 문자열을 출력할 수 있음

1. string을 배열에 넣으면서 숫자가 있는지 확인하고 숫자가 있다면 그 숫자를 int형으로 변환하여 N으로 넣고
배열에서 숫자가 들어간 인덱스 값을 idx에 넣음
2. 숫자가 0, 1, 2 인덱스에 들어가 있는 case를 나누고 출력
3. 다음에 나올 숫자에 맞는 문자열을 작성하기 위해 outstr 함수 제작하여 string 리턴
*/