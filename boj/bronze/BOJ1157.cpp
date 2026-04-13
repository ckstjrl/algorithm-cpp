// BOJ 1157. 단어 공부 / B1
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string w;
    cin >> w;

    int cnt[26] = { 0 };

    for (char c : w) {
        int idx = c - 'A';
        if (idx >= 26) {
            idx -= 32;
        }

        cnt[idx]++;
    }

    int max_c = 0;
    int max_i = 0;
    for (int a : cnt) {
        if (a > max_c) {
            max_c = a;
        }
    }

    int max_cnt = 0; 
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == max_c) {
            max_cnt++;
            max_i = i;
        }
    }

    if (max_cnt != 1) {
        cout << "?" << "\n";
    }

    else {
        cout << char('A' + max_i) << "\n";
    }
}

/*
A를 빼주면서 배열에 cnt를 저장할 수 있도록 함
소문자의 경우에는 -32를 추가로 진행해주면서 같이 cnt에 저장

이후 cnt배열의 max 값을 찾고 max 값을 갖는 요소가 1개인지 아닌지 판단 후 대문자 출력
*/