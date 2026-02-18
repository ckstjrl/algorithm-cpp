// PGS 131701. 연속 부분 수열 합의 개수 / Lv.2
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int N = elements.size();
    
    set<int> sum;
    for (int e = 1; e <= N; e++) {
        
        for (int i = 0; i < N; i++) {
            
            int s = 0;
            for (int j = i; j < e + i; j++) {
                if (j < N) {
                    s += elements[j];
                }

                else {
                    s += elements[j - N];
                }
            }
            sum.insert(s);
        }
    }
    return sum.size();
}

/*
원형 수열이므로 인덱스 범위를 초과하는 문제 발생 -> N을 빼주는 방향으로 해결
3중 for문 사용
첫 번째 for문의 경우 부분수열의 원소 개수
두 번째 for문의 경우 부분수열의 시작 인덱스
세 번째 for문의 경우 합해주는 과정
set 자료구조를 활용하여 중복된 값을 자동으로 걸러주는 역할로 활용
*/