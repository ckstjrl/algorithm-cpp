// BOJ 14891. 톱니바퀴 / G5
#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<int> arr[5];
void clock(int n) {
	int temp = arr[n].back();
	arr[n].pop_back();
	arr[n].push_front(temp);
}

void anti_clock(int n) {
	int temp = arr[n].front();
	arr[n].pop_front();
	arr[n].push_back(temp);
}

int main() {

	for (int c = 1; c <= 4; c++) {
		string s;
		cin >> s;
		for (int i = 0; i < 8; i++) {
			arr[c].push_back(s[i] - '0');
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int n, w;
		cin >> n >> w;
		
		int d[5] = { 0 };
		d[n] = w;

		for (int i = n; i > 1; i--) {
			if (arr[i][6] == arr[i - 1][2]) {
				break;
			}
			else {
				d[i - 1] = -1 * d[i];
			}
		}

		for (int i = n; i < 4; i++) {
			if (arr[i][2] == arr[i + 1][6]) {
				break;
			}
			else {
				d[i + 1] = -1 * d[i];
			}
		}

		for (int i = 1; i <= 4; i++) {
			if (d[i] == 1) clock(i);
			else if (d[i] == -1) anti_clock(i);
		}
	}
	int score = 0;
	if (arr[1][0] == 1) score += 1;
	if (arr[2][0] == 1) score += 2;
	if (arr[3][0] == 1) score += 4;
	if (arr[4][0] == 1) score += 8;

	cout << score << "\n";
}

/*
입력이 붙어있기 때문에 string으로 받고 '0'을 빼주는 방식으로 int형식으로 만듦
자료구조 덱 활용
시계방향의 경우 뒤에서 뽑아서 앞으로 넣고
반시계방향의 경우 앞에서 뽑아서 뒤로 넣음

d라는 배열을 만들어서 0은 아무것도 안하고 1을 시계방향, -1은 반시계방향으로 회전할 수 있게 저장
for (int i = n; i > 1; i--) 를 통해 n기준으로 왼쪽을 판단하고
for (int i = n; i < 4; i++) 를 통해 n기준으로 오른쪽을 판단함
이후 d를 1부터 4까지 순회하면서 회전 구현

while문 종료 후 12시 방향의 극을 확인하여 점수를 계산하여 출력
*/