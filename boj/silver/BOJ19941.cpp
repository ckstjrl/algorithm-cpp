// BOJ 19941. 햄버거 분배 / S3
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        bool eat = false;
        if (s[i] == 'P') {
            for (int l = K; l > 0; l--) {
                if ((i - l) >= 0 && s[i - l] == 'H') {
                    cnt++;
                    s[i - l] = ' ';
                    eat = true;
                    break;
                }
            }

            if (!eat){
                for (int r = 1; r <= K; r++) {
                    if ((i + r) < N && s[i + r] == 'H') {
                        cnt++;
                        s[i + r] = ' ';
                        break;
                    }
                }
            }
        }
    }
    cout << cnt << "\n";
}

/*
그리디 활용
사람의 왼쪽 끝부터 오른쪽 끝까지 순서대로 확인하는 과정을 통해 햄버거를 먹을 수 있는지 없는지 확인
햄버거를 먹는 순간 break를 통하여 반복문에서 나옴
*/