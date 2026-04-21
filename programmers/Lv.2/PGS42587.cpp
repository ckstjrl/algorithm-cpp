// PGS 42587. 프로세스 / Lv.2
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int N = priorities.size();
    
    deque<int> process;
    for (int i = 0; i < N; i++) {
        process.push_back(i);
    }
    
    int cnt = 0;
    while (!process.empty()) {
        int cur = process.front();
        process.pop_front();
        
        int max_p = *max_element(priorities.begin(), priorities.end());
        
        if (priorities[cur] == max_p) {
            cnt++;
            priorities[cur] = 0;
            if (cur == location) {
                return cnt;    
            }
        }
        
        else process.push_back(cur);
    }
}

/*
deque 자료구조 활용
앞에서 뽑아서 우선순위 확인하고 우선순위 가장 높으면 priorities 벡터 값을 0을 변경하고
우선 순위가 가장 높은 프로세스가 아닌 경우 push_back 진행
*/