// BOJ 2075. N번째 큰 수 / S3
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N * N; i++) {
		int temp;
		cin >> temp;

		pq.push(temp);
		if (pq.size() > N) {
			pq.pop();
		}
	}
	cout << pq.top() << "\n";
}



/*
int main() {
	int N;
	cin >> N;

	vector<int> arr(N*N, 0);
	for (int i = 0; i < N * N; i++) {
		cin >> arr[i];
	}

	sort(arr.rbegin(), arr.rend());

	cout << arr[N-1] << "\n";
}
*/

/*
처음에 단순하게 생각해서 모든 숫자를 배열로 받은 후
내림차순 정렬하여 N-1 인덱스를 뽑는 방법으로 고려했지만, 시간 초과 발생

우선순위 큐 자료구조 활용
최소 힙 pq를 만든 후 input을 받으면서 N개 넘으면 top(=최소값)을 뽑아내는 방법을 활용해서
결과적으로 가장 큰 N개의 숫자만 남게 했고 top을 출력하면서 N번째로 큰 숫자를 출력
*/