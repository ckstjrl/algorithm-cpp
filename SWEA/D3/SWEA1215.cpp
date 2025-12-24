//SWEA 1215. 회문1 / D3
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int T = 10;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;

		char arr[8][8];

		for (int i = 0; i < 8; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < 8; j++) {
				arr[i][j] = s[j];
			}
		}

		vector<string> N_word;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 9-N; j++) {
				string c;
				string r;
				for (int t = 0; t < N; t++) {
					c += arr[i][j+t];
					r += arr[j + t][i];
				}
				N_word.push_back(c);
				N_word.push_back(r);
			}
		}
		int cnt = 0;
		for (string i : N_word) {
			string i_;
			for (int a = N-1; a >= 0; a--) {
				i_ += i[a];
			}
			if (i == i_) {
				cnt++;
			}
		}
		cout << "#" << tc << ' ' << cnt << "\n";
	}
}

/*
input을 배열로 받아서
가로로 N글자인 문자열 세로로 N글자인 문자열 모든 종류를 N_word에 담는다
N_word를 순회하면서 회문 조건을 확인하고
맞으면 cnt를 증가시키는 방법으로 문제 풀이
*/