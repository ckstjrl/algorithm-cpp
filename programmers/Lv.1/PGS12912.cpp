/* PGS 12912. 두 정수 사이의 합 / Lv.1 */
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if (a<=b){
        for(int i = a; i <= b; i++){
            answer += i;
        }
        return answer;
    }
    else {
        for(int i = b; i <= a; i++){
            answer += i;
        }
        return answer;
    }
}

/*
a, b가 대소관계에 상관없이 나오기 때문에 직접 if절을 통해 경우 분리로 풀이
*/