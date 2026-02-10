// BOJ 10815. 숫자 카드 / S5
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> card(N);
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	sort(card.begin(), card.end());

	int M;
	cin >> M;

	vector<int> check(M, 0);
	for (int i = 0; i < M; i++) {
		int c;
		cin >> c;

		if (c < card[0] || c > card[N-1]) continue;

		int l = 0;
		int r = N-1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (card[m] == c) {
				check[i] = 1;
				break;
			}

			else {
				if(card[m] > c) {
					r = m - 1;
				}
				else {
					l = m + 1;
				}
			}
		}

	}
    for (int ch : check) {
        cout << ch << " ";
    }
}

/*
먼저 가지고 있는 카드를 내림차순 정렬 진행
먼저 카드의 최솟값보다 작은 정수, 최댓값보다 큰 정수는 제외
주어진 정수가 카드 중 있는지 없는지 이분탐색 진행
있다면 check 벡터에 1을 작성하는 방식으로 확인
이후 for문을 진행하여 벡터에 있는 값을 출력
*/