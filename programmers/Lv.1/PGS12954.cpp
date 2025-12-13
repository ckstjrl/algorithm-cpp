/* PGS 12954. x만큼 간격이 있는 n개의 숫자 / Lv.1 */

#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for (int i = 0; i < n; i++) {
        long long num = x;
        num = x + x*i;
        answer.push_back(num);
    }
    return answer;
}

/*
for 문을 통하여 n번 반복하여
num = x + x*i 라는 점화식을 통하여
answer배열에 숫자를 넣는 방식으로 문제 풀이 진행
*/