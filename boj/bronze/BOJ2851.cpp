// BOJ 2851. 슈퍼 마리오 / B1

#include <iostream>

using namespace std;

int main() {
	int mush[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		cin >> mush[i];
	}
	int scores[10] = { 0 };
	scores[0] = mush[0];
	for (int i = 1; i < 10; i++) {
		scores[i] = scores[i - 1] + mush[i];
	}
	
	int ans = scores[0];
	int min = 0;
	for (int j = 0; j < 9; j++) {
		if (abs(100 - scores[j]) >= abs(100 - scores[j + 1])) {
			ans = scores[j + 1];
		}
	}
	cout << ans << "\n";
}

/*
한번 안먹으면 뒤에 있는 버섯은 못먹기 때문에
mush 배열의 0번 인덱스 부터 각 인덱스까지 합한 값을 scores배열에 저장
scores 배열의 요소를 100과의 차이로 비교하면서 100과의 차이가 작으면 ans에 넣음
만약 차이가 같다면 더 큰 값을 넣도록 조건문 작성
*/