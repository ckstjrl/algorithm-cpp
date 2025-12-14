/* PGS 12916. 문자열 내 p와 y의 개수 / Lv.1 */
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int num_p = 0;
    int num_y = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'p' || s[i] == 'P'){
            num_p += 1;
        }
        else if (s[i] == 'y' || s[i] == 'Y'){
            num_y += 1;
        }
    }
    if (num_p != num_y) {
        answer = false;
    }
    

    return answer;
}

/*
문자열 인덱스를 활용하여 for문을 통해 p, y의 개수를 세는 방식으로 문제 풀이
str.length() -> 문자열 길이
C++은 영어 대소문자를 구분하므로
대소문자 관계없이 개수를 세야하는 문제 특성상 조건문 작성시 대문자이거나 소문자이거나 라는 조건을 작성해야 함
*/