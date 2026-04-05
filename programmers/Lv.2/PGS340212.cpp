// PGS 340212. [PCCP 기출문제] 2번 / 퍼즐 게임 챌린지 / LV.2
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int l = 1;
    int r = 100000;
    while (l <= r) {
        int m = (l + r) / 2;
        long long total_time = 0;
        for (int i = 0; i < diffs.size(); i++) {
            if (diffs[i] <= m) {
                total_time += times[i];
            }
            else {
                total_time += (diffs[i] - m) * (times[i] + times[i - 1]) + times[i];
            }
        }
        
        if (total_time <= limit) {
            answer = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    
    return answer;
}

/*
이분탐색 활용
*/