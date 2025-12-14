/* PSG 12947. 하샤드 수 / Lv.1 */
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int a = x;
    while(a) {
        sum += a%10;
        a /= 10;
    }
    
    if (x % sum == 0) {
        answer = true;
    } else {
        answer = false;
    }
    return answer;
}

/*
x값을 if문에서 다시 사용해야하므로
a라는 int변수를 x로 초기값 설정 후 자릿수의 합을 구함
자리수 합을 sum에 넣고 x를 나누었을 떄 나머지가 0이면 true 아니면 false를 출력하는 방식으로 문제 풀이
*/