// BOJ 9655. 돌 게임 / S5
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    if (N % 2 == 0) {
        cout << "CY" << "\n";
    }
    else {
        cout << "SK" << "\n";
    }
}

/*
가져갈 수 있는 돌의 개수가 1, 3으로 둘 다 홀수이기때문에
돌의 개수가 홀수이면 상근이가 이기고
돌의 개수가 짝수이면 창영이가 이기는 게임이 된다.
*/