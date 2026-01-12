// BOJ 1138. 한 줄로 서기 / S2
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> tall_n(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> tall_n[i];
	}
	deque<int> l;
	deque<int> r;
	l.push_back(N);

	for (int i = N - 1; i > 0; i--) {
		if (tall_n[i] == 0) l.push_front(i);

		else if (tall_n[i] == l.size()) l.push_back(i);

		else if (tall_n[i] > l.size()) {
			
            while (tall_n[i] != l.size()) {
				int temp = r.front();
				r.pop_front();
				l.push_back(temp);
			}

			l.push_back(i);
		}

		else if (tall_n[i] < l.size()) {

			while (tall_n[i] != l.size()) {
				int temp = l.back();
				l.pop_back();
				r.push_front(temp);
			}

			l.push_back(i);
		}
	}

	for (int i = 0; i < l.size(); i++) {
		cout << l[i] << ' ';
	}

	for (int i = 0; i < r.size(); i++) {
		cout << r[i] << ' ';
	}
}

/*
자료구조 덱을 활용하여 문제 풀이 진행
제일 키가 큰 사람부터 세우면 풀이 가능
제일 키가 큰 사람은 무조건 0이므로 l에 집어 넣음
이후 두번째 큰 사람부터 확인하면 되는데 
키가 m번째로 큰 사람이 갖을 수 있는 숫자는 0 ~ m까지 이다.
이때 0일때는 큰사람들 보다 왼쪽에 세우면 되므로 l.push_front(N-m)진행
m인 경우는 큰사람들보다 오른쪽에 세우면 되므로 l.push_back(N-m) 진행
하지만 중간의 숫자들에서는 
l의 길이보다 작은지 큰지를 확인하면 된다
l의 길이보다 숫자가 작으면 r의 앞부분을 l길이와 숫자가 동일할때까지 가져오고 push_back 진행하면 되고
반대고 숫자가 더 크면 l의 뒷부분을 r의 앞부분으로 보내고 push_back 진행하면 된다.
이 방법은 백준 커서라는 문제와 유사한 풀이 방식이다.
*/