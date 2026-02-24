// PGS 131127. 할인 행사 / Lv.2
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int disl = discount.size();
    int wantl = want.size();
    
    if (disl < 10) {
        return 0;
    }
    
    unordered_map<string, int> wantMap;
    for (int i = 0; i < wantl; i++) {
        wantMap[want[i]] = number[i];
    }
    
    unordered_map<string, int> temp;
        
    for(int i = 0; i < 10; i++) {
        temp[discount[i]]++; 
    }
    
    for (int i = 0; i <= disl - 10; i++) {
        bool ok = true;
        for (string w : want) {
            if (temp[w] < wantMap[w]) {
                ok = false;
                break;
            }
        }
        
        if (ok) {
            answer++;
        }
        
        if (i == disl - 10) break;
        
        temp[discount[i]]--;
        temp[discount[i + 10]]++;
    }
    
    
    return answer;
}

/*
key를 품목 이름, value를 원하는 개수로 해서 unordered_map 생성하여 문제 풀이 진행
10개를 변할때마다 체크해도 가능하지만, 한 칸씩 이동한다고 생각하면 10개 중 맨앞의 품목이 하나 빠지고, 새로운 품목이 하나 들어오는 과정이라 생각하면 더 빠르게 연산 가능
이러한 과정을 통해 구한 temp map의 품목 개수가 원하는 수보다 크다면 answer 증가
*/