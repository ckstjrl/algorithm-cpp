// BOJ 4659. 비밀번호 발음하기 / S5
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string aeiou = "aeiou";
    while(1){
        string pw;
        cin >> pw;

        if (pw == "end") {
            break;
        }

        bool ok = true;

        int acnt = 0;
        int acc = 0;
        int bcc = 0;
        char tmp = ' ';
        for (char c : pw) {
            if (acc == 3 || bcc == 3) {
                ok = false;
                break;
            }

            if (count(aeiou.begin(), aeiou.end(), c)) {
                bcc = 0;
                acnt++;
                acc++;
                if ((c != 'e' && c != 'o') && tmp == c) {
                    ok = false;
                    break;
                }
            }
            else {
                acc = 0;
                bcc++;
                if (tmp == c) {
                    ok = false;
                    break;
                }
            }

            tmp = c;
        }

        if (ok && acnt && acc < 3 && bcc < 3) {
            cout << "<" << pw << ">" << " is acceptable." << "\n";
        }

        else {
            cout << "<" << pw << ">" << " is not acceptable." << "\n";
        }
    }
    
}

/*
총 모음의 개수 acnt
연속된 모음의 개수 acc
연속된 자음의 개수 bcc

pw를 순회하면서 모음인지 아닌지 먼저 판단
모음인 경우 bcc 초기화, acc 추가, acnt 추가, ee, oo 빼고 연속인지 아닌지 확인
자음인 경우 acc 초기화, bcc 추가, 연속인지 아닌지 확인

ok가 true이고 acc, bcc가 3보다 작고, acnt가 0이 아닌 경우는 가능
이외는 전부 불가능
*/