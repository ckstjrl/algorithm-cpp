/* BOJ 2920. 음계 / bronze2 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int>v(8);
	
	for (int i = 0; i < 8; i++) {
		cin >> v[i];
	}

	if (v == arr) {
		cout << "ascending\n";
	}
	else {
		reverse(arr.begin(), arr.end());
		if (v == arr) {
			cout << "descending\n";
		}
		else {
			cout << "mixed\n";
		}
	}
}

/*
1. vector<배열 원소 타입> 배열 이름
2. vector<배열 원소 타입> 배열 이름(원소 개수)
3. input이 1 2 3 4 5 이런 형식인 경우 for(int i = 0; i < N; i++) 활용
4. reverse 활용시 #include <algorithm> 필요
5. reverse(arr.begin(), arr.end()) 기억
*/