// BOJ 1874. 스택 수열 / S2
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    stack<int> s;
    vector<char> ans;
    int cur = 1;
    bool ok = true;

    for (int i = 0; i < N; i++) {
        int tar;
        cin >> tar;

        while (cur <= tar) {
            s.push(cur);
            ans.push_back('+');
            cur++;
        }

        if (s.top() == tar) {
            s.pop();
            ans.push_back('-');
        }
        else {
            ok = false;
            break;
        }
    }

    if (ok) {
        for (char a : ans) {
            cout << a << "\n";
        }
    }
    else {
        cout << "NO" << "\n";
    }
}

/*
숫자를 받으면서 현재 값이 target보다 작거나 같으면 stack에 집어 넣는과정
-> while문이 종료된 후 stack에서 가장 마지막에 들어간 수가 target과 동일하다면 stack에서 뽑아준다
-> 다시 for문으로 올라가서 반복
-> 만약 stack의 마지막에 들어간 수가 target과 같지 한다면 ok를 false로 변경하고 끝냄
ok이가 끝까지 true라면 만들 수 있다는 의미이고 +, -로 되어 있응 배열을 출력
ok가 false라면 NO를 출력
*/