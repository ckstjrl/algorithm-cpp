// BOJ 10804. 카드 역배치 / B2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int card[21] = { 0 };
	for (int c = 0; c < 21; c++) {
		card[c] = c;
	}
	for (int n = 0; n < 10; n++) {
		int a, b;
		cin >> a >> b;
		int m = b - a;
		for (int i = 0; i <= m / 2; i++) {
			int temp = card[a + i];
			card[a + i] = card[b - i];
			card[b - i] = temp;
		}
	}
	for (int c = 1; c < 20; c++) {
		cout << card[c] << ' ';
	}
	cout << card[20];
}

/*
카드라는 배열을 만들어 0으로 최신화 한후 각 인덱스에 맞게 번호 넣어줌
10번의 과정을 반복하며
for (int i = 0; i <= m / 2; i++) {
        int temp = card[a + i];
        card[a + i] = card[b - i];
        card[b - i] = temp;
    }
과정을 통해 앞뒤 카드 교환
이후 1번 인덱스부터 20번 인덱스까지 출력
*/