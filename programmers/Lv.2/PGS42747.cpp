// PGS 42747. H-Index / Lv.2
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int n = citations.size();
    
    int h = 0;
    bool ok = true;
    
    while (ok) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (citations[i] >= h) {
                cnt++;
            }
        }
        if (cnt < h) {
            ok = false;
            break;
        }
        h++;
    }
    
    return h-1;
}

/*
h값을 0부터 증가시키면서 citations 요소중 h보다 크거나 같은 요소의 개수가 h이상인지 체크
만약 조건을 만족하지 않는 지점이 발생하면 반복문을 종료한 후 그 h 값에서 -1 한 값을 정답으로 출력
*/