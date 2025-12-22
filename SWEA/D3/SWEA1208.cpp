// SWEA 1208. Flatten / D3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T = 10;
	for(int t = 1; t<=T; t++){
		int D;
		cin >> D;
		vector<int> arr(100);
		for (int i = 0; i < 100; i++) {
			cin >> arr[i];
		}
		while (D--) {
			int max_i = max_element(arr.begin(), arr.end()) - arr.begin();
			int min_i = min_element(arr.begin(), arr.end()) - arr.begin();
			arr[max_i]--;
			arr[min_i]++;
		}
		int ans = *max_element(arr.begin(), arr.end()) - *min_element(arr.begin(), arr.end());
		cout <<"#"<< t << ' ' << ans << "\n";
	}
}

/*
vector 요소 100로 설정한 후 input으로 받아서 최신화
이후 dump 수만큼 while문을 돌리면서
최대값의 인덱스, 최소값의 인덱스를 찾아서 최댓값 -1 최솟값 -1을 진행하여 dump활동 구현
이후 최댓값 - 최솟값을 출력
*/