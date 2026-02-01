// BOJ 1259. 팰린드롬수 / B1
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s;
	while (1) {
		cin >> s;
		if (s == "0") break;
		else {
			int size = s.length();
			string n;
			for (int i = 0; i < size; i++) {
				n += s[size - i - 1];
			}

			if (s == n) {
				cout << "yes" << "\n";
			}
			else {
				cout << "no" << "\n";
			}
		}
	}
}

/*
숫자를 문자열로 받고
문자열을 뒤집어서 새로운 문자열을 만들고 둘을 비교하여 출력
*/