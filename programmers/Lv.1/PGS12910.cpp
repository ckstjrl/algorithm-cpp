/* PGS 12910. 나누어 떨어지는 숫자 배열 / Lv.1 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    sort(arr.begin(), arr.end());
    vector<int> answer;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % divisor == 0) {
            answer.emplace_back(arr[i]);
        }
    }
    
    if (!answer.size()) {
        answer.emplace_back(-1);
    }
    return answer;
}

/*
답안이 오름차순이어야 하므로 나누어지는 값인 arr를 오름차순으로 변경하고 시작
나누어 떨어지면 answer에 넣어줌
만약 반복문을 진행했음에도 answer에 아무 숫자도 없다면 -1을 넣어주는 방식으로 문제 풀이
*/