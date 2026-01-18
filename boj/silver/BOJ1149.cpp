// BOJ 1149. RGB거리 / S1
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	long long r, g, b;
	cin >> r >> g >> b;

	long long dpR, dpG, dpB;
	dpR = r;
	dpG = g;
	dpB = b;

	for (int i = 2; i <= N; i++) {
		cin >> r >> g >> b;

		long long nextR = r + min(dpG, dpB);
		long long nextG = g + min(dpR, dpB);
		long long nextB = b + min(dpR, dpG);

		dpR = nextR;
		dpG = nextG;
		dpB = nextB;
	}

	cout << min({ dpR, dpG, dpB }) << "\n";
}

/*
앞집에서 어떤 것을 선택했는지가 뒤에 영향을 준다.
뒤에서는 앞집에서 선택하지 않은 두가지중 값이 저렴한 한가지를 고르면 되는 문제
이 경우 전부 탐색하는 방법이 있지만 메모리와 시간복잡도가 높기때문에 다이나믹프로그래밍 활용
현재 칠하는 색이 R이라고 하면 앞에선 G, B 둘 중 한 색을 칠했어야 한다.
저렴한 방법을 찾기 위해 진행하는 것이므로 dpG, dpR 중 작은 값을 넣는다.
dp가 진행되어야 하므로 칠하는 3가지 경우를 모두 연산해주고 dpO에 각각의 경우를 넣어준다.
이 방식으로 진행하여 그중 가장 작은 값을 가지고 있는 것을 출력한다.
*/