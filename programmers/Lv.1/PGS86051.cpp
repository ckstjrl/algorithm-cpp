/* PGS 86051. 없는 숫자 더하기 / Lv.1 */

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<bool> a(10, false);
    for (int n : numbers) {
        a[n] = true;
    }
    for (int i = 0; i < a.size(); i++){
        if (!a[i]) {
            answer += i;
        }
    }
    return answer;
}

/*
요소 10개가 모두 false로 초기값을 갖는 vector 만들기 -> vector<bool> a(10, false);
numbers요소를 뽑아서 vector a에 해당 인덱스에 ture로 변경
이렇게 하면 없는 숫자만 false로 남아 있음
다시 반복문을 통해서 !a[i] 로 false 인덱스 값을 answer에 더해주는 방식으로 문제 풀이
*/