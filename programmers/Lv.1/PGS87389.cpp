/* PGS 87389. 나머지가 1이 되는 수 찾기 / Lv.1 */

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 1) {
            answer = i;
            break;
        }
    }
    return answer;
}

/*
문제 그대로 n 자기자신보다 작은 숫자중 나머지가 1이 되는 숫자를 찾으면 됨
가장 작은 숫자를 찾아야 하기 때문에 찾으면 break를 통해 반복문에서 빠져나오는 방식으로 문제풀이
*/