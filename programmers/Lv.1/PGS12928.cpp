/* PGS 12928. 약수의 합 / Lv.1 */

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            answer += i;
        }
    }
    return answer;
}

/*
for 문으로 i를 1부터 n까지 반복하며
n을 i로 나누었을 때 나머지가 0이면 n의 약수이므로 answer에 더해주는 방법으로 풀이
*/