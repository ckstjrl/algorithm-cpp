//BOJ 11399. ATM / S4
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> time(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> time[i];
	}

	sort(time.begin(), time.end());

	for (int i = 1; i < N; i++) {
		time[i] = time[i] + time[i - 1];
	}

	int sum = 0;
	for (int t : time) {
		sum += t;
	}
	cout << sum << "\n";
}

/*
줄 서는 번호를 굳이 알 필요는 없기때문에 그냥 내림차순 정렬 진행
시간 내림차순 정렬한 후 다이나믹 프로그래밍 진행
이후 배열에 있는 요소들의 합 출력
*/