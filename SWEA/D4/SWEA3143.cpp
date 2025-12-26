// SWEA 3143. 가장 빠른 문자열 타이핑 / D4
#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		string A;
		string B;
		cin >> A >> B;

		int al = A.length();
		int bl = B.length();

		int cnt = 0;
		for (int i = 0; i <= al - bl; i++) {
			bool a = true;
			for (int j = 0; j < bl; j++) {
				if (A[i + j] != B[j]) {
					a = false;
					break;
				}
			}
			if (a) {
				cnt++;
				i += (bl-1);
			}
		}
		int typ = al - cnt * (bl - 1);
		cout << "#" << tc << ' ' << typ << "\n";
	}
}

/*
A문자열과 B문자열을 받고,
두 문자열의 길이를 변수에 저장한다
A문자열 0번 인덱스부터 (A길이 - B길이) 인덱스까지 for문을 돌고
A안에 B가 있는지 없는지 확인하는 bool 변수 a를 기본 true로 해 놓고
B문자열 길이만큼 비교를 하는 과정에서 둘이 다르다면 false로 변환하고 break
만약 동일하다면 cnt를 1 증가시키고 다음 확인할 A의 인덱스를 B문자열 길이만큼 이동 시켜서 확인
이 과정을 통해 cnt를 구하고
최종적으로 타이핑하는 횟수는 cnt + A문자열 길이 + cnt * B문자열 길이를 출력한다.
*/