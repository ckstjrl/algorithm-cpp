// BOJ 2456. 나는 학급 회장 / B1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int sum[4] = { 0 };
	int cnt3[4] = { 0 };
	int cnt2[4] = { 0 };

	vector<vector<int>> v;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < 4; j++) {
			int a;
			cin >> a;
			sum[j] += a;
			if (a == 3) cnt3[j] += 1;
			if (a == 2) cnt2[j] += 1;
		}
	}
	for (int j = 1; j < 4; j++) {
		v.push_back({ sum[j], cnt3[j], cnt2[j], j });
	}
	sort(v.rbegin(), v.rend());
	if (v[0][0] == v[1][0] && v[0][1] == v[1][1] && v[0][2] == v[1][2]) {
		cout << 0 << " " << v[0][0];
	}
	else {
		cout << v[0][3] << " " << v[0][0];
	}
}

/*
총합, 3점 받은 횟수, 2점받은 횟수, 후보번호를 저장하고
vector에 담아내고 내림차순 정렬 진행
내림차순 정렬한 후 1등과 2등이 총합, 3점 받은 횟수, 2점 받은 횟수 모두 동일하다면 
0 최대 총합을 출력하고
아닌 경우
1등의 후보번호와 총합 출력
*/