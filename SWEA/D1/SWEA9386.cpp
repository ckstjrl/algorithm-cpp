// SWEA 9386. 연속한 1의 개수 / D1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		int cnt = 0;
		vector<int> one_cnt;

		string s;
		cin >> s;
		vector<int> arr(N, 0);
		for (int i = 0; i < N; i++) {
			arr[i] = s[i] -'0';

			if (arr[i] == 1) {
				cnt++;
				one_cnt.emplace_back(cnt);
			}
			else{
				cnt = 0;
			}
		}

		cout << "#" << t << ' ' << *max_element(one_cnt.begin(), one_cnt.end()) << "\n";
	}
}

/*
1이 나올 때마다 개수를 세고 cnt를 one_cnt vector에 넣음
이후 max값을 구하면 연속된 1 개수의 최댓값을 구할 수 있음
*/