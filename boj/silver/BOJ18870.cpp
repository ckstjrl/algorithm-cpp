// BOJ 18870. 좌표 압축 / S2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<pair<int, long long>> axis(N);
	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		axis[i] = { num, i };
	}

	sort(axis.begin(), axis.end());

	int cnt = -1;
	long long tmp = 100000001;
	for(int i = 0; i < N; i++) {
		long long a = axis[i].first;
		int b = axis[i].second;
		if (tmp != a) {
			cnt++;
			tmp = a;
		}
		axis[i] = { b, cnt };
	}

	sort(axis.begin(), axis.end());

	for (int i = 0; i < N; i++) {
		int o = axis[i].second;
		cout << o << " ";
	}
}

/*
숫자와 들어온 순서를 pair에 담아서 vector에 넣고 sort 진행
숫자 기준으로 sort해야 하기 때문에 숫자를 first에 넣고 진행
이제 순서대로 숫자를 변경해야하는데 중복된 숫자가 존재할 수 있기 때문에 변경된 숫자를 tmp에 임시 저장함
첫번째 숫자는 앞 숫자가 없기 때문에 tmp에 범위를 넘는 큰 숫자를 초기값으로 설정
숫자 변경이 끝나면 다시 인덱스 순서대로 정렬
압축한 숫자를 출력
*/