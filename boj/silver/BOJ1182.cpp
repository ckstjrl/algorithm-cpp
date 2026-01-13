//BOJ 1182. 부분 수열의 합 / S2
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, S;
	cin >> N >> S;
	vector<int> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int cnt = 0;
	for (int i = 1; i < (1 << N); i++) {
		int sum = 0;
		
		for (int j = 0; j < N; j++) {
			if(i & (1<<j)) sum += num[j];
		}

		if (sum == S) cnt++;
	}
	cout << cnt << "\n";
}

/*
비트마스킹을 활용하여 전체 부분집합을 구함
for (int i = 0; i < (1 << N); i++)으로 하게되면 공집합 포함이므로
for (int i = 1; i < (1 << N); i++)로 진행
*/