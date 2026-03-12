// BOJ 15903. 카드 합체 놀이 / S2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<long long> cards(N);
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }

    while (M--) {
        sort(cards.begin(), cards.end());
        long long temp = cards[0] + cards[1];
        cards[0] = temp;
        cards[1] = temp;
    }

    long long score = 0;
    for (long long c : cards) {
        score += c;
    }

    cout << score << "\n";
}

/*
정렬 활용 풀이
쉽게 생각하면 제일 작은 수 2개를 합해서 최신화 해주는 방법이 제일 쉬운 방법
vector에서 작은 수 2개를 for문 등 구할 수 있는 방법은 여러가지가 있겠지만
쉽게 오름차순 정렬을 진행하고 0번 인덱스와 1번 인덱스를 더해주고 최신화 하는 방향으로 진행
*/