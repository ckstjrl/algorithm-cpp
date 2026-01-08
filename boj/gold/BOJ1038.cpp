// BOJ 1038. 감소하는 수 / G5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> num;
vector<int> arr;
void combination(int deep, int nxt, int r) {
	if (deep == r) {
		long long x = 0;
		for (int i = r - 1; i >= 0; i--) {
			x = x * 10 + arr[i];
		}
		num.push_back(x);
		return;
	}

	for (int i = nxt; i <= 9; i++) {
		arr.push_back(i);
		combination(deep + 1, i + 1, r);
		arr.pop_back();
	}
}
int main() {
	for (int i = 1; i <= 10; i++) {
		combination(0, 0, i);
	}
	

	int N;
	cin >> N;

	sort(num.begin(), num.end());

	if (N >= num.size()) cout << -1 << "\n";

	else {
			cout << num[N] << "\n";
	}
}

/*
조합 함수 작성하여 감소하는 수 x를 제작
이후 10 C 1 ~ 10 C 10까지 연산하여 벡터 num에 집어 넣고
sort 진행
이후 input으로 받은 N이 num의 size보다 크면 -1 출력
아니면 num의 N번째 인덱스 출력
*/