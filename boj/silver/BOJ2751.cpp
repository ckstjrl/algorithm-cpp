// BOJ 2751. 수 정렬하기 2 / S5
#include <iostream>
#include <set>

using namespace std;

int main() {
	int N;
	cin >> N;

	set<int> s;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		s.insert(num);
	}

	for (int n : s) {
		cout << n << "\n";
	}
}

/*
수 정렬하기
algorithm STL을 사용할까 하다가
set 자료구조를 활용함
set의 경우 숫자가 들어오면 자동으로 정렬을 하기 떄문에 따로 처리할 것 없이
insert 한 후 앞에서 부터 출력
*/