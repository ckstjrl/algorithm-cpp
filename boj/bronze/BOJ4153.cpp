// BOJ 4153. 직각삼각형 / B3
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int tri[3];
        cin >> tri[0] >> tri[1] >> tri[2];

        // 종료 조건
        if (tri[0] == 0 && tri[1] == 0 && tri[2] == 0)
            break;

        sort(tri, tri + 3);

        if (tri[0] * tri[0] + tri[1] * tri[1] == tri[2] * tri[2])
            cout << "right\n";
        else
            cout << "wrong\n";
    }
}

/*
피타고라스 법칙 활용
*/