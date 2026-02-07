// BOJ 10816. 숫자 카드 2 / S4
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    unordered_map<int, int> num;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        num[n]++;
    }

    int M;
    cin >> M;
    for (int j = 0; j < M; j++) {
        int m;
        cin >> m;
        cout << num[m] << ' ';
    }
}

/*
해시 테이블 활용
해시 테이블 키를 가지고 있는 숫자로 하고, 숫자의 빈도를 값으로 저장
이후 M번 나오는 숫자를 키로해서 값을 출력
*/