// BOJ 11723. 집합 / S5

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	set<int> S;
	set<int> S_in;
	for (int i = 1; i <= 20; i++) {
		S_in.insert(i);
	}

	while (N--) {
		string p;
		int m;
		cin >> p;

		if (p == "add") {
			cin >> m;
			S.insert(m);
		}

		else if (p == "remove") {
			cin >> m;
			S.erase(m);
		}

		else if (p == "check") {
			cin >> m;
			if (S.count(m)) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}

		else if (p == "toggle") {
			cin >> m;
			if (S.count(m)) {
				S.erase(m);
			}
			else {
				S.insert(m);
			}
		}

		else if (p == "all") {
			S = S_in;
		}

		else if (p == "empty") {
			S.clear();
		}
	}
}

/*
C++의 set 자료구조 사용 : 자동으로 중복 제거, 삽입 순서와 상관 없이 정렬
set.insert(i) -> i 삽입
set.erase(i) -> i 삭제
set.count(i) -> i 개수 세기
set.clear() -> 빈 set으로 만들기

ios::sync_with_stdio(false);
cin.tie(nullptr);
빠른 cin, cout 코드
시간 초과 문제 위 코드로 해결
*/