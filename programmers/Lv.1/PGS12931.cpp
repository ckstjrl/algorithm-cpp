/* PGS 12931. 자리수 더하기 / Lv.1 */

#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    
    while (n){
        answer += n % 10;
        n /= 10;
    }

    return answer;
}

/*
while문을 통하여 answer에 n을 10으로 나눈 나머지를 더하고
n을 10으로 나눈 몫을 최신화 해주는 방식으로 문제 풀이
*/