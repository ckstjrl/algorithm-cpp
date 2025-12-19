// BOJ 10448. 유레카 이론 / B1
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int tri[46] = { 0 };
	for (int i = 1; i < 46; i++) {
		tri[i] = (i * (i + 1)) / 2;
	}
	int T;
	cin >> T;
	while (T--) {
		int num;
		bool A = false;
		cin >> num;
		for (int i = 1; i <= 45; i++) {
			for (int j = 1; j <= 45; j++) {
				for (int k = 1; k <= 45; k++) {
					if (tri[i] + tri[j] + tri[k] == num) {
						A = true;
						break;
					}
				}
			}
		}
		if (A) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}

/*
tri 배열을 45까지만 만들면 input 범위인 1000을 만족시킬 수 있음
tri를 만든 후 3개의 합으로 num을 만들 수 있는지 bool 타입으로 확인
true면 1출력
false면 0 출력
*/