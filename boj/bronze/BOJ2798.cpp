// BOJ 2798. 블랙잭 / B2
#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
int N, M;
int ans = 0;
void nCr(int start, int deep, int sum) {
	if (deep == 3) {
		if (sum <= M) {
			ans = max(ans, sum);
		}
		return;
	}
	for (int i = start; i < N; i++) {
		nCr(i + 1, deep + 1, sum + num[i]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	
	num.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	nCr(0, 0, 0);
	cout << ans << "\n";
}

/*
N의 크기가 100으로 크지 않기 때문에 조합함수(재귀)를 활용해서 3개를 뽑아서
그 합을 구해 M가 가장 가까운 수를 ans에 넣고 출력
*/