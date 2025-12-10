/*BOJ 11650. 좌표 정렬하기 / S5*/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<tuple<int, int>> arr;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		arr.push_back({ x, y });
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		cout << get<0>(arr[i]) << " " << get<1>(arr[i]) << "\n";
	}
}

/*
1. vector 내부에 tuple 넣기 -> vector.push_back({x, y})
2. sort 방식 -> sort(vector.begin(), vector.end())
3. get<0>(vector[i]) -> 벡터 인덱스 안의 튜플의 0번 인덱스 값 가져오기
*/