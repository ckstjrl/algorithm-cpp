/* PGS 76501. 음양 더하기 / Lv.1 */

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for (int i = 0; i < signs.size(); i++){
        if (signs[i]){
            answer += absolutes[i];
        }
        else {
            answer -= absolutes[i];
        }
    }
    return answer;
}

/*
signs와 absolutes의 vector크기는 동일하다.
signs가 true이면 answer에 더해주고 false이면 빼주는 로직으로 풀이
*/