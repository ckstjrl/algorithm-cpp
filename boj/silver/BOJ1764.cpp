// BOJ 1764. 듣보잡 / S4
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<string> no_hear(N);
	vector<string> no_see(M);
	vector<string> no_hear_see;
	for (int i = 0; i < N; i++) {
		cin >> no_hear[i];
	}
	for (int j = 0; j < M; j++) {
		cin >> no_see[j];
	}
	sort(no_hear.begin(), no_hear.end());
	sort(no_see.begin(), no_see.end());

	no_hear_see.reserve(min(N, M));
	set_intersection(no_hear.begin(), no_hear.end(), no_see.begin(), no_see.end(), back_inserter(no_hear_see));
	
	cout << no_hear_see.size() << "\n";
	for (string name : no_hear_see) {
		cout << name << "\n";
	}
	
}

/*
처음 이중 for문을 활용해 중복되는 이름이 있으면 no_hear_see 벡터에 넣어주는 과정으로 진행
-> 시간 초과

시간 초과 문제 해결하기 위해
교집합 방식 활용

no_hear_see.reserve(min(N, M));
-> 교집합의 최대 공간은 N과 M중 작은 숫자에 따라 가기 때문에 min(N, M)만큼 공간을 미리 확보
vector.resize(n)는 실제로 n개의 크기를 가지는 벡터가 되고
vector.reverve(n)은 실제 크기는 변하지 않지만, 저장할 수 있는 공간을 미리 확보하는 용도

set_intersection(no_hear.begin(), no_hear.end(), no_see.begin(), no_see.end(), back_inserter(no_hear_see));
-> 두 벡터를 교집합, 사용하기 전에 두 벡터는 정렬되어있어야 함.
set_intersection은 정렬되어 있는 범위에서만 동작
back_inserter(no_hear_see)가 교집합 요소를 벡터에 넣어줌
*/

/* 시간초과 발생 코드
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<string> no_hear(N);
	vector<string> no_see(M);
	vector<string> no_hear_see;
	for (int i = 0; i < N; i++) {
		cin >> no_hear[i];
	}
	for (int j = 0; j < M; j++) {
		cin >> no_see[j];
		for (int i = 0; i < N; i++) {
			if (no_see[j] == no_hear[i]) {
				no_hear_see.push_back(no_see[j]);
			}
		}
	}


	sort(no_hear_see.begin(), no_hear_see.end());
	cout << no_hear_see.size() << "\n";
	for (string name : no_hear_see) {
		cout << name << "\n";
	}
}
*/