/* PGS 12932. 자연수 뒤집어 배열로 만들기 / Lv.1 */
#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while(n) {
        answer.emplace_back(n%10);
        n /= 10;
    }
    return answer;
}
/*
n이 0이 될때까지 while 반복
n을 10으로 나눈 나머지를 vector에 넣고
n을 10으로 나눈 몫으로 n을 최신화
*/