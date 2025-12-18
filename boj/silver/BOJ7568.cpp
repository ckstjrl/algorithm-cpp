// BOJ 7568. 덩치 / S5
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> tall(N, 0);
	vector<int> weight(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> weight[i] >> tall[i];
	}
	vector<int> cnt(N, 1);
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (tall[x] < tall[y] && weight[x] < weight[y]) {
				cnt[x]++;
			}
		}
	}
	for (int i = 0; i < N-1; i++) {
		cout << cnt[i] << ' ';
	}
	cout << cnt[N-1];
}

/*
몸무게와 키를 따로 vector로 만들고 input으로 최신화
cnt라는 vector를 만들고 만약 x 인덱스 몸무게, 키 둘다 큰 인덱스의 수를 세서 cnt[x]에 최신화
이후 출력 진행
*/
