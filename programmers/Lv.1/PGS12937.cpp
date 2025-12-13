/* PGS 12937. 짝수와 홀수 / Lv. 1 */

#include <string>
using namespace std;

string solution(int num) {
    string answer = "";
    if (num%2 == 0) {
        answer = "Even";
    } else {
        answer = "Odd";
    }
    return answer;
}

/*
2로 나눈 나머지가 0이라면 "Even" 출력
아니라면 "Odd" 출력
방식으로 문제 풀이
*/