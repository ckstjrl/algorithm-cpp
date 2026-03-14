// PGS 42586. 기능개발 / Lv.2

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int N = progresses.size();
    
    vector<int> days(N);
    for (int i = 0; i < N; i++) {
        days[i] = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
    }
    
    int dev_day = days[0];
    int cnt = 1;
    
    for (int i = 1; i < N; i++) {
        if (dev_day >= days[i]) {
            cnt++;
        }
        else {
            answer.push_back(cnt);
            dev_day = days[i];
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    
    return answer;
}

/*
모든 기능의 완성일을 저장하고 앞의 완성일보다 뒤에 완성일이 작을 경우 cnt로 세서 answer에 출력
*/