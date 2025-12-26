// BOJ 2161. 카드1 / S5
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	queue<int> q;
	vector<int> ans;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	
	while (q.size() != 0) {
		ans.emplace_back(q.front());
		q.pop();
		if (q.size() == 0) break;
		q.push(q.front());
		q.pop();
	}
	for (int i : ans) {
		cout << i << ' ';
	}
}

/*
queue 자료구조 활용
queue.front() -> 큐의 맨 앞 요소 리턴
queue.back() -> 큐의 맨 뒤 요소 리턴
queue.push(i) -> 큐의 맨 뒤에 i 추가
queue.pop() -> 큐의 맨 앞 요소 삭제
queue.size() -> 큐의 요소 개수 리턴

풀이 과정
큐를 만들고
큐의 맨앞에 있는 요소를 vector에 넣어주고
큐에서는 삭제,
(이때 큐의 크기가 0인지 아닌지 확인)
이후 큐의 맨 앞 요소를 뒤에 넣어주고
큐 맨앞 요소 삭제,
큐의 사이즈가 0이 될 때까지 위 동작 반복
이후 vector에 들어간 요소들을 출력
*/
