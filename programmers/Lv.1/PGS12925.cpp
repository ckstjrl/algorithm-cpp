/* PGS 12925. 문자열을 숫자로 바꾸기 / Lv.1 */

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    answer = stoi(s);
    return answer;
}

/*
문자열을 숫자로 변경하는 방법 -> stoi(s) (stod : 문자열을 double로)
숫자를 문자열로 변경하는 방법 -> to_string(i)
*/