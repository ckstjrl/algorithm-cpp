// BOJ 11053. 가장 긴 증가하는 부분 수열 / S2
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<long long> ans;
	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		if(ans.empty() || ans.back() < num) {
			ans.push_back(num);
		}
		else {
			int l = 0;
			int r = ans.size();

			while (l < r) {
				int m = (l + r) / 2;
				if (ans[m] < num) {
					l = m + 1;
				}
				else {
					r = m;
				}
			}
			ans[l] = num;
		}
	}
	cout << ans.size() << "\n";
}

/*
이분탐색 활용
빈 배열이거나 배열의 마지막 요소가 지금 input으로 받은 숫자보다 작다면 
지금 input으로 받은 숫자를 배열에 넣어준다
위 경우가 아니라면 해당 숫자가 들어갈만한 위치를 이분탐색으로 찾는다
중간에 있는 값이 input보다 작으면 l = m + 1로 변경하고 같거나 크다면 r = m으로 변경한다
while문이 종료되면 배열의 인덱스 l의 요소를 input으로 변경해준다.
이후 정답 배열의 길이를 출력

예시
10 20 10 50 30 25 이 input인 경우
ans = [10, 20]
10 -> l = 0, r = 1 => m = 0 => ans[0] == 10 => r = m = 0 => ans[0] = 10
ans = [10, 20]
50 -> ans = [10, 20, 50]
30 -> l = 0, r = 2 => m = 1 => ans[1] < 30 => l = 2 => ans[2] = 30
ans = [10, 20, 30]
25 -> l = 0, r = 3 => m = 1 => ans[1] < 25 => l = 2 => m = 2 => ans[2] > 25 => r = 2 => ans[2] = 25
ans = [10, 20, 25]
ans.size() = 3

이렇게 최신화하는 마지막 숫자가 작을 수록 뒤에 들어올 수 있는 숫자의 범위가 증가하기 때문이다.
*/