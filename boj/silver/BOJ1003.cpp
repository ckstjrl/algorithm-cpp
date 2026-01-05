// BOJ 1003. 피보나치 함수 / S3
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
vector<pair<int, int>> fidp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fidp.push_back({ 1, 0 });
	fidp.push_back({ 0, 1 });
	for (int i = 2; i < 41; i++) {
		int x = fidp[i - 1].first + fidp[i - 2].first;
		int y = fidp[i - 1].second + fidp[i - 2].second;
		fidp.push_back({ x, y });
	}
	
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;
		cout << fidp[N].first << ' ' << fidp[N].second << "\n";
	}
}

/*
피보나치 함수의 경우 f(n) = f(n-2) + f(n-1)이 식을 따라가므로
n에서 0과 1이 출력되는 횟수는 n-1, n-2에서 0과 1이 출력되는 수의 합이 된다.
이러한 부분을 활용하여 다이나믹프로그래밍 사용
*/