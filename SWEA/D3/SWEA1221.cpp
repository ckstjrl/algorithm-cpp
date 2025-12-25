// SWEA 1221. GNS / D3
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        string tc;
        cin >> tc;

        string num[10] = { "ZRO","ONE","TWO","THR","FOR","FIV","SIX","SVN","EGT","NIN" };
        int cnt[10] = { 0 };

        int N;
        cin >> N;

        for (int k = 0; k < N; k++) {
            string innum;
            cin >> innum;

            for (int i = 0; i < 10; i++) {
                if (num[i] == innum) {
                    cnt[i]++;
                    break;
                }
            }
        }

        cout << tc << "\n";
        for (int i = 0; i < 10; i++) {
            for (int c = 0; c < cnt[i]; c++) {
                cout << num[i] << ' ';
            }
        }
        cout << "\n";
    }
}

/*
숫자를 표시하는 문자열을 미리 배열에 넣고 크기가 동일한 cnt배열을 만들어서
input을 받으며 문자열과 동일한 인덱스의 cnt 값을 증가시킴
이후 문자열이 담김 배열을 순회하면서 cnt만큼 출력하는 방법으로 출력
*/