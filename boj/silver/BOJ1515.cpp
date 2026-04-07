// BOJ 1515. 수 이어 쓰기 / S2
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    int num = 0;
    int idx = 0;

    while (idx < S.length()) {
        num++;
        string snum = to_string(num);

        for (char c: snum) {
            if (idx < S.length() && c == S[idx]) {
                idx++;
            }
        }
    }
    cout << num << "\n";
}

/*
구현
현재 숫자를 num
snum으로 string으로 만든 후 앞에서부터 입력 문자열의 현재 인덱스와 비교
210325329로 예시를 들면
num     idx     S[idx]
2       0       2
10      1 -> 2  1 -> 0 
13      3       3               
25      4 -> 5  2 -> 5
32      6 -> 7  3 -> 2
39    
정답은 39가 된다
*/