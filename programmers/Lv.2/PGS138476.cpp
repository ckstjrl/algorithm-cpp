// PGS 138476. 귤 고르기 / Lv.2
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> kinds(10000001);
    for (int i = 0; i < tangerine.size(); i++) {
        kinds[tangerine[i]]++;
    }
    
    sort(kinds.rbegin(), kinds.rend());
    
    int ea = 0;
    for(int i = 0; i < 10000001; i++) {
        ea += kinds[i];
        if (ea >= k) {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}

/*
단순하게 생각해서 귤의 크기는 상관 없고 종류가 가장 적으면 되는 문제
귤의 사이즈를 백터의 인덱스 값으로 하고 해당 인덱스의 요소를 개수로 정리
이후 내림차순 정렬
내림차순 정렬 이후 앞에서 부터 더하면서 기준 값이 k보다 같거나 커지는 순간이 되면
answer를 i+1로 하고 for문을 빠져나옴
*/