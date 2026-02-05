// BOJ 10814. 나이순 정렬 / S5
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> age(N);
	vector<string> name(N);
	for (int i = 0; i < N; i++) {
		int a;
		string na;
		cin >> a >> na;

		age[i] = { a, i };
		name[i] = na;
	}
	sort(age.begin(), age.end());

	for (int j = 0; j < N; j++) {
		cout << age[j].first << ' ' << name[age[j].second] << "\n";
	}
}

/*
나이와 가입 순번을 같이 pair로 벡터에 넣고
다른 벡터에 이름을 넣는다
이 상태로 나이가 들어있는 벡터를 정렬하게 되면
나이 기준 정렬 이후 가입 순번 기준 정렬하게 된다.
이렇게 되면 동일한 나이의 경우 가입 순번대로 정렬되므로
pair의 first는 나이이므로 출력
이름 벡터의 pair의 second 인덱스를 출력
*/