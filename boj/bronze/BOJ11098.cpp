/* BOJ 11098. 첼시를 도와줘! / B2 */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;
		
		vector<tuple<int, string>> fa;

		for (int i = 0; i < N; i++) {
			int price;
			string name;
			cin >> price >> name;
			fa.push_back({ price, name });
		}
		sort(fa.begin(), fa.end());

		cout << get<1>(fa[N-1]) << '\n';
	}
}

/*
테스트 케이스는 T
for문으로 T번 반복
선수 수는 N
int와 string을 요소로 갖는 tuple을 요소로 갖는 vector 생성후
tuple 내부 int에는 선수 비용, string에는 선수 이름을 넣은 후
sort를 통해 정렬한 후
마지막 인덱스에 있는 선수의 이름을 출력함.
*/