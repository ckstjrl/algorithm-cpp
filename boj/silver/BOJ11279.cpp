// BOJ 11279. 최대 힙 / S2
#include <iostream>
#include <vector>
#include<queue>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int> pq;

    while (N--) {
        int x;
        cin >> x;

        if (x == 0) {
            if (!pq.empty()) {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else {
                cout << 0 << "\n";
            }
        }

        else{
            pq.push(x);
        }
    }
}


/*
최대힙 자료 구조 활용
문제에 따라 최대 힙이 비어있을 경우 0이 들어면 0 출력 아닌경우 최댓값 출력 후 삭제
둘다 아닌 경우 x를 최대 힙에 넣어주는 방법으로 문제풀이
*/