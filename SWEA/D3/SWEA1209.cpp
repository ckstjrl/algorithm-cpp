// SWEA 1209. Sum / D3
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int T = 10;
	while (T--) {
		int t;
		cin >> t;
		
		int max_v = 0;
		int sumRL = 0;
		int sumLR = 0;

		vector<int> sumCol(100, 0);
		for (int i = 0; i < 100; i++) {
			int sumRow = 0;

			for (int j = 0; j < 100; j++) {
				int x;
				cin >> x;
				sumRow += x;
				sumCol[j] += x;
				if (i == j) sumLR += x;
				if (i + j == 99) sumRL += x;
			}

			max_v = max(max_v, sumRow);
		}

		max_v = max(max_v, sumRL);
		max_v = max(max_v, sumLR);
		
		int maxCol = *max_element(sumCol.begin(), sumCol.end());
		max_v = max(max_v, maxCol);
		
		cout << "#" << t << ' ' << max_v << "\n";
	}
}

/*
최댓값 max_v, 왼->오 대각선 sumLR, 오->왼 대각선 sumRL 0으로 초기값 설정
sumCol은 vector로 만들고 같은 열에 있는 숫자들 더해줌
sumRow는 for i 문에서 0으로 최신화하면서 같은 행에 있는 숫자들 더해줌
sumLR은 행 열의 인덱스 값이 같을 때 더해줌
sumRL는 행 열의 인덱스 합이 99일 때 더해줌
sumPow의 경우 for i문에서 0으로 최신화되므로 for j문 끝나면 바로 최댓값과 비교해서 넣어줌
반복문 종료후 최댓값과 sumRL, sumLR 값과 비교
sumCol의 경우 모든 반복문 이후 vector내에서의 최댓값을 구한후 전체 최댓값과 비교

이런식으로 문제 풀이

처음 문제 풀이 당시 로직은 동일하나 arr를 저장하여 문제 풀이
이렇게 풀이한 것과 현재 풀이의 메모리 차이가 날 것으로 예상했으나
8kb 감소, 시간은 2ms 감소
*/