// BOJ 2775. 부녀회장이 될테야 / B1
#include <iostream>

using namespace std;

int main() {
	int apt[15][15] = { 0 };
	for (int i = 1; i < 15; i++) {
		apt[0][i] = i;
		apt[i][1] = 1;
	}
	for (int f = 1; f < 15; f++) {
		for (int h = 2; h < 15; h++) {
			apt[f][h] = apt[f - 1][h] + apt[f][h - 1];
		}
	}
	
	int T;
	cin >> T;

	while (T--) {
		int k, n;
		cin >> k >> n;
		cout << apt[k][n] << "\n";
	}
}

/*
일단 2차원 배열을 만든다.
문제에서 14층 14호까지의 범위를 주어줬기 때문에 0층을 포함해 14층, 14호까지 배열을 15 X 15 사이즈로 설정
열 0번인덱스는 사용하지 않고, 0으로 유지
미리 모든 인원수를 배열에 채워넣고 input으로 들어오는 층 호수의 값을 출력하는 방법으로 진행
x층의 y호 인원은 (x층의 y-1호 인원) + (x-1층 y호 인원)이므로 이렇게 점화식을 작성하여 구함 (DP)
이후 층 호수를 받아 출력
*/