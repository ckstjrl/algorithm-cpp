// PGS 42885. 구명보트 / Lv.2
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.rbegin(), people.rend());
    int l = 0;
    int r = people.size() - 1;
    while (l <= r){
        if(l != r && people[l] + people[r] <= limit){
            l++;
            r--;
        }
        else{
            l++;
        }
        answer++;
    }
    return answer;
}

/*
그리디 알고리즘 활용
이진탐색 진행
먼저 무거운 순으로 정렬을 한 후
제일 무거운 사람 + 제일 가벼운 사람 <= limit인 경우 같이 탈출
아닌 경우 무거운 사람만 탈출 하는 방식으로
l과 r이 동일해 질때까지 answer++를 하며 진행하면 결과 도출
*/