// PGS 87390. n^2 배열 자르기 /Lv.2
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long l = left / n;
    long long dl = left % n;
    long long r = right / n;
    long long dr = right % n;
    
    if (l == r) {
        for (int i = dl; i <= dr; i++) {
            if (i < l) {
                answer.push_back(l + 1);
                continue;
            }
            answer.push_back(i + 1);
        }
    }
    
    else {
        for (int i = dl; i < n; i++) {
            if (i < l) {
                answer.push_back(l + 1);
                continue;
            }
            answer.push_back(i + 1);
        }
        
        while (l < r - 1) {
            l++;
            for (int i = 0; i < n; i++) {
                if (i < l) {
                answer.push_back(l + 1);
                continue;
                }
            answer.push_back(i + 1);
            }
        }
        
        for (int i = 0; i <= dr; i++) {
            if (i < r) {
                answer.push_back(r + 1);
                continue;
            }
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}

/*
left와 right의 col과, row을 찾아서 규칙을 적용하고 그 규칙에 따라 조건문으로 나누어 풀이
but 코드가 굉장히 복잡하고 조건부가 많아서 가독성이 저하됨
이에 따라 다른 방식을 고민함
*/

/*
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long k = left; k <= right; k++) {
        long long row = k / n;
        long long col = k % n;
        answer.push_back(max(row, col) + 1);
    }
    return answer;
}
*/

/*
다시 규칙을 찾아서 결국 원하는 답은 똑같이 row, col을 구하고 그에 맞는 규칙을 찾는 것인데
둘 중 큰 값에 1을 구하면 결국 같은 값이 도출됨
이 코드가 조건부가 없기 때문에 가독성 측면에서는 유리함
시간 복잡도 측면에서는 동일
*/