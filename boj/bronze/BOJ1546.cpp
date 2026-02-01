// BOJ 1546. 평균 / B1
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	float N;
	cin >> N;

	float max_s = 0;
	float sum = 0;
	
	for (int i = 0; i < N; i++) {
		float s;
		cin >> s;
		sum += s;
		if (s > max_s) {
			max_s = s;
		}
	}
	
	cout << (sum * (100 / max_s)) / N << "\n";
}

/*
처음엔 백터에 모든 점수를 받아 새로운 점수로 변경하여 풀이할 생각을 했지만,
너무 여러 단계를 거치는 것 같아
식을 정리하여 새로운 평균 식을 구하고 그에 필요한 연산만 진행
*/