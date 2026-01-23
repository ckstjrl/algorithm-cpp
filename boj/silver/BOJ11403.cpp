// BOJ 11403. 경로 찾기 / S1
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<vector<int>> arr(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				/*arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);*/
				if (arr[i][k] && arr[k][j]) arr[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
}
/*
플로이드 워셜 알고리즘 활용
3중 for문 내부에 주석으로 처리된 부분 + 연결되지 않는 부분을 INF(매우 큰 수)로 처리하면 기본 플루이드 워셜 알고리즘
하지만 이 문제에서는 갈 수 있는지 없는지를 판단하는 것이 목적이므로 변형 필요
arr에서 연결되지 않는 부분을 INF로 입력하지 않고 0으로 입력을 하게 되면 
arr[i][k] && arr[k][j]를 만족한다면 갈 수 있다는 의미가 된다.
이 방법을 활용하여 갈 수 있는지 없는지 여부만 판단하여 출력
*/