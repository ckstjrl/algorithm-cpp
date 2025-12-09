/*BOJ 10989. 수 정렬하기 3 / B1*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	int cnt[10001] = { 0 };

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		cnt[x] += 1;
	}

	for (int i = 0; i < 10001; ++i) {
		while (cnt[i] != 0) {
			--cnt[i];
			cout << i << "\n";
		}
	}
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int x : v) {
		cout << x << "\n";
	}
}
*/
// vector로 받는 경우 메모리 초과 발생

/*
1. int cnt[10001] = {0}; 로 인덱스가 10001개인 배열 생성
2. 각 인덱스의 숫자가 들어오면 개수를 배열에 넣어줌
3. 반복문을 통하여 인덱스 번호를 인덱스 원소만큼 출력해줌
*/