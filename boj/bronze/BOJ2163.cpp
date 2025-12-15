// BOJ 2163. 초콜릿 자르기 / B1
#include <iostream>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	cout << M * N - 1;
}

/*
N X M 초콜릿을 자를 수 있는 방법은
(N-1) + N(M-1) or (M-1) + M(N-1) 인데
결국 두 식다 정리하면 NM - 1로 정리 된다.
이 식을 cout으로 출력하는 방식으로 문제 풀이
*/