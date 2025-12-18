// BOJ 2947. 나무 조각 / B1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> stick(5);
	for (int i = 0; i < 5; i++) {
		cin >> stick[i];
	}
	while (stick != vector<int>{ 1, 2, 3, 4, 5 }) {
		for (int s = 0; s < 4; s++) {
			if (stick[s] > stick[s + 1]) {
				int temp = stick[s];
				stick[s] = stick[s + 1];
				stick[s + 1] = temp;
				cout << stick[0] << ' ' << stick[1] << ' ' << stick[2] << ' ' << stick[3] << ' ' << stick[4] << '\n';
			}
		}
	}
}

/*
while 문을 활용해서 1,2,3,4,5로 정렬될 때까지 반복 진행
for 문으로 정렬 시작
한번 움직이면 출력하도록 설정하여 문제 풀이
*/