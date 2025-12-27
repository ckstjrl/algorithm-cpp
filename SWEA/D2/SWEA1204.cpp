// SWEA 1204. 최빈수 구하기 / D2
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int tc;
		cin >> tc;

		vector<int>s_cnt (101, 0);
		for (int i = 0; i < 1000; i++) {
			int score;
			cin >> score;
			s_cnt[score]++;
		}

		int max_s = *max_element(s_cnt.begin(), s_cnt.end());
		int max_idx = max_element(s_cnt.begin(), s_cnt.end()) - s_cnt.begin();

		for (int s = max_idx; s < 101; s++) {
			if (s_cnt[s] == max_s && s > max_idx) {
				max_idx = s;
			}
		}

		cout << "#" << tc << ' ' << max_idx << "\n";
	}
}

/*
점수를 인덱스 값으로 한 vector를 만들고 input을 받으면 해당 인덱스를 증가시킴
이후 max_s를 최댓값으로 설정하고 max_idx는 최댓값을 갖는 가장 작은 인덱스를 넣음
이후 for문을 통해 max_idx보다 크면서 인덱스 100보다 작은 범위를 반복하면서
요소의 값이 max_s와 동일하고 인덱스 값이 max_idx보다 더 큰 값이 있으면 max_idx를 최신화 시켜 출력
이 과정을 통해 동일한 빈도수를 갖은 점수가 있는 경우 높은 점수를 출력할 수 있도록 설정
*/