// SWEA 2005. 파스칼의 삼각형
#include <iostream>

using namespace std;

int tri[10][10] = { 0 };
int main() {
	for (int i = 0; i < 10; i++) {
		tri[i][0] = 1;
		tri[i][i] = 1;
	}
	for (int i = 2; i < 10; i++) {
		for (int j = 1; j < i; j++) {
			tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
		}
	}
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;

		cout << "#" << tc << "\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				cout << tri[i][j] << ' ';
			}
			cout << "\n";
		}
	}
}

/*
삼각형을 담을 배열을 미리 전역 변수로 선언
N의 최대가 10까지 이므로 10 X 10 이차원 배열 선언
배열에 고정적으로 1이 들어가는 위치에 먼저 1을 넣어주고
나머지는 점화식을 활용해 구해서 넣어줌
삼각형 이차원 배열을 완성한 후
N에 맞게 출력하는 방법으로 문제 풀이
*/