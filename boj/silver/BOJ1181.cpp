// BOJ 1181. 단어 정렬 / S5
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	vector<set<string>> dic(51);

	int N;
	cin >> N;

	while (N--) {
		string s;
		cin >> s;

		int l = s.length();
		dic[l].insert(s);
	}
	for (int i = 1; i < 51; i++) {
		if (!dic[i].empty()) {
			for (auto it = dic[i].begin(); it != dic[i].end(); it++) {
				cout << *it << "\n";
			}
		}
	}
}
/*
조건이 길이에 따라 먼저 정렬, 길이가 동일하다면 사전 기준 정렬이므로
동일한 길이의 단어를 set에 넣어주면 자동으로 해결

vector의 요소를 set으로 설정한 후
vector의 인덱스를 문자열의 길이로 설정
문자열의 길이에 맞게 set에 넣어주면 중복된 문자열도 해결, 사전 기준 정렬도 해결

이후 vector을 순회하면서 set이 비어있지 않다면
set을 순회하여 문자열들 출력

!!! set 순회 방식
for (auto it = set.begin(); it != set.end(); it++) 
	cout << *it << "\n";

vector와는 다른 방식으로 순회
set.begin()은 set의 시작 주소, set.end()는 set의 마지막 주소
주소값을 증가시키면서 역참조 방식으로 출력 진행
*/