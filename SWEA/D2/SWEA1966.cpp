// SWEA 1966. 숫자를 정렬하자 / D2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		vector<int> arr(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		sort(arr.begin(), arr.end());

		cout << "#" << t;
		for (int a : arr) {
			cout << ' ' << a;
		}
		cout << "\n";
	}
}

/*
int N;
cin >> N;
vector<int> arr(N, 0);

이렇게 N을 런타임에서 받을 경우 arr[N]은 사용하지 못하고 무조건 vector로 받아야한다.
*/