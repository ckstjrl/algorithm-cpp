// BOJ 2805. 나무 자르기 / S2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;

	
	vector<long long> tree(N);
	long long tallest = 0;
	for (long long i = 0; i < N; i++) {
		cin >> tree[i];
		tallest = max(tallest, tree[i]);
	}

	long long l = 0;
	long long r = tallest;
	long long ans = 0;

	while (l <= r) {
		long long mid = (l + r) / 2;
		long long cut = 0;
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid) {
				cut += (tree[i] - mid);
			}
		}

		if (cut == M) {
			ans = mid;
			break;
		}
		else if (cut > M) {
			ans = mid;
			l = mid + 1;
		}
		else if (cut < M) {
			r = mid - 1;
		}
	}
	cout << ans << "\n";
}

/*
완전탐색으로 문제 풀이했다가 시간초과 발생
고민하다가 이분탐색으로 진행
자르는 길이를 이분탐색으로 찾는다는 목적으로 문제 풀이
l = 0으로 r = 가장 큰 나무 높이로 설정한 후
mid 계산. mid보다 큰 나무로만 잘린 나무 계산
잘린 나무의 길이가 M보다 크다면 l을 높여서 더 높은 높이 찾고
M보다 작다면 r을 낮춰서 잘린 나무의 길이가 M이상이 되게 만듦

이분탐색으로 진행하는 과정에서 계속 틀렸습니다. 나와서 왜 틀렸는지 이해가 안갔는데
input의 범위를 보고 int의 범위를 넘는 것 확인 후 long long 타입 사용
*/


// 완전 탐색을 통해 정답 구하기 -> 시간초과
/*
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> tree(N);
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
	}

	int tallest = *max_element(tree.begin(), tree.end());
	
	int ans = 0;
	for (int x = tallest - 1; x > 0; x--) {
		int cut = 0;
		for (int i = 0; i < N; i++) {
			if (tree[i] > x) {
				cut += (tree[i] - x);
			}
		}
		if (cut >= M) {
			ans = x;
			break;
		}
	}
	cout << ans << "\n";
}
*/