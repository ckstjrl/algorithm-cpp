// BOJ 1173. 운동 / B2
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;
	vector<int> bpm;
	bpm.emplace_back(m);
	int cnt = 0;
	int min = 0;
	while (cnt < N) {
		if (m + T > M) { 
			min = -1;
			break;
		}
		else if (bpm[min] + T <= M) {
			bpm.emplace_back(bpm[min] + T);
			cnt++;
		}
		else {
			if (bpm[min] - R >= m) {
				bpm.emplace_back(bpm[min] - R);
			}
			else {
				bpm.emplace_back(m);
			}
		}
		min++;
	}
	cout << min;
}

/*
vector에 맥박수를 저장하면서 진행 -> min을 인덱스로 활용
cnt는 운동 횟수 저장하고 min은 총 시간을 의미함
cnt가 N과 같아질 때까지 while문 반복
while문 안에서 초반 맥박수 + 운동하면 올라가는 맥박 수가 최대값보다 크다면 min애 -1을 넣고 반복문 종료
아닌 경우 맥박수가 최댓값을 넘어가지 않도록 조절하고
맥박수가 최솟값보다 작게 계산된다면 최솟값으로 최신화
이 과정을 통해 운동하는데 총 걸린 시간은 min으로 출력 가능
*/