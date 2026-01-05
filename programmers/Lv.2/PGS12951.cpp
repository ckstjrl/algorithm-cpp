// PGS 12951. JadenCase 문자열 만들기 / Lv.2
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    if ('a' <= s[0] && s[0] <= 'z'){
        s[0] -= ('a' - 'A');
    }

    for (int i = 0; i < s.length(); i++){
        if (s[i] == ' '){
            if ('a' <= s[i+1] && s[i+1] <= 'z'){
                s[i+1] -= ('a' - 'A');
            }   
        }
        else {
            if ('A' <= s[i+1] && s[i+1] <= 'Z'){
                s[i+1] += ('a' - 'A');
            }  
        } 
    }
    return s;
}

/*
일단 첫번째 문자부터 소문자 알파벳이라면 대문자로 변경
이후 for 반복문을 돌면서 해당 index의 문자가 공백이라면 뒤가 소문자 알파벳일때 대문자로 변경
해당 index의 문자가 공백이 아닌데 대문자라면 소문자로 변경 하는 방식으로 문제 풀이
answer 문자열을 따로 만들어서 s의 문자열을 넣어주는 방식보다는 그냥 s자체를 변경하고 출력하는 방식 선택
소문자 대문자 변환은 아스키 코드의 순서를 활용하여 연산
*/