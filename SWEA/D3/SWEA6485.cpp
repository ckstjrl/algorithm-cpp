// SWEA 6485. 삼성시의 버스 노선 / D3
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		int P;
		cin >> N;

		vector<int> a(N, 0);
		vector<int> b(N, 0);
		for (int n = 0; n < N; n++) {
			cin >> a[n] >> b[n];
		}

		cin >> P;

		vector<int> c(P, 0);
		for (int j = 0; j < P; j++) {
			cin >> c[j];
		}

		vector<int> cnt(P, 0);
		for (int n = 0; n < N; n++) {
			int A = a[n];
			int B = b[n];
			for (int i = 0; i < P; i++) {
				if (c[i] >= A && c[i] <= B) {
					cnt[i]++;
				}
			}
		}

		cout << "#" << t;
		for (int num : cnt) {
			cout << ' ' << num;
		}
		cout << "\n";
	}
}

/*
N대의 버스의 노선 번호를 작은건 vector a에 큰건 vector b에 저장
이후 vector c에 노선의 번호들을 작성한 후
이중 for문을 통해 c를 통과하는 버스의 개수를 count해서 vector cnt에 입력
이후 vector cnt를 출력
*/