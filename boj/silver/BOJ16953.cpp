// BOJ 16953. A -> B / S2
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    cin >> A >> B;

    int cnt = 1;
    bool ok = true;
    while (A < B) {
        if (B % 2 == 0) {
            B /= 2;
            cnt++;
        }

        else if ((B - 1) % 10 == 0) {
            B = (B - 1) / 10;
            cnt++;
        }

        else {
            cout << -1 << "\n";
            ok = false;
            break;
        }
    }

    if (ok) {
        if (B != A){
            cout << -1 << "\n";
        }
        else {
            cout << cnt << "\n";
        }
    }
}

/*
A에서 2를 곱하고 오른쪽에 1을 붙이는 연산을 진행하면 너무 많은 경우의 수가 발생하기 때문에
B가 2의 배수이면 2로 나누고 오른쪽이 1이면 1을 삭제하는 방법을 통해 B를 A와 동일하게 만들 수 있는지 없는지 유무를 확인
B를 A로 만드는 과정에서 두 경우다 포함 되지 않을 경우는 ok라는 bool을 false로 변경하고 -1을 출력
두 경우를 다 만족 시켜서 B > A 조건과 맞지 않아 while문을 통과했더라고 A == B가 아닌 경우가 존재하기 때문에
ok가 true인 경우 중에서도 한번 더 필더를 진행함
만약 bool ok를 확인하지 않을 경우에는 -1 이 두번 출력되는 문제가 발생하기 때문에 필수적으로 필요했음
*/