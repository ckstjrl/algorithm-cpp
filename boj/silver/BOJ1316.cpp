// BOJ 1316. 그룹 단어 체커 / S5

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	int cnt = N;
	for (int n = 0; n < N; n++) {
		string s;
		cin >> s;
		vector<int> c;
		
		for (int i = 1; i < s.length(); i++) {
			c.emplace_back((int)s[i-1]);
			if (s[i - 1] != s[i]) {
				if (count(c.begin(), c.end(), (int)s[i]) > 0) {
					cnt -= 1;
					break;
				}
			}
		}

	}
	cout << cnt;
}

/*
N번 반복하여 string 확인
string의 인덱스를 아스키코드 숫자로 변환하여 vector에 넣고
만약 앞 char와 뒤 char가 동일하지 않다면
vector에 해당 문자의 아스키코드 숫자가 있는지 확인후
있다면 전체 cnt 개수에서 -1을 해주고 더 이상 그 문자열을 확인할 필요가 없으므로 break
이후 cnt 출력하는 방식으로 문제 풀이
*/