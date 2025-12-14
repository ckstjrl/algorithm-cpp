/* PGS 12934. 정수 제곱근 판별 / Lv.1 */
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long a = sqrt(n);
    if (a*a == n) {
        answer = (a+1)*(a+1);
    } else {
        answer = -1;
    }
    return answer;
}

/*
a에 sqrt(n)을 long long자료형으로 담고
만약 sqrt(n)이 양의 정수라면 a*a는 n과 동일해지고 sqrt(n)이 double 자료형이였다면 a*a != n이므로
if 문을 활용하여 확인
이후 양의 정수라면 a+1의 제곱을 아니라면 -1을 출력하는 방식으로 문제풀이
#include <cmath>에 sqrt, pow 등이 포함되어 있다는 것 확인
*/