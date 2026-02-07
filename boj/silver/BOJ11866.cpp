// BOJ 11866. 요세푸스 문제 0 / S4
#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    deque<int> circle;
    for(int i = 1; i < N + 1; i++){
        circle.push_back(i);
    }

    cout << "<";
    while (circle.size() != 1) {
        for(int i = 0; i < K - 1; i++) {
            int temp;
            temp = circle.front();
            circle.pop_front();
            circle.push_back(temp);
        }
        int pop_n;
        pop_n = circle.front();
        circle.pop_front();
        cout << pop_n << ", ";
    }

    cout << circle.front() << ">" << "\n";
}

/*
deque 활용
K-1번까지 뒤로 보내고 K번째를 출력하면서 pop
*/