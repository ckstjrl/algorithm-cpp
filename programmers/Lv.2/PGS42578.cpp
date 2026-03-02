// PGS 42578. 의상 / Lv.2
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> kind_cnt;
    for (vector<string> p : clothes) {
        kind_cnt[p[1]]++;
    }
    
    long long ans = 1;
    for (pair<const string, int> kc : kind_cnt) {
        ans *= (kc.second + 1);
    }
    
    int answer = ans - 1;
    return answer;
}

/*
경우의 수를 구하기 위해서 먼저 옷 종류에 따라 의상의 개수를 저장함
한 옷 종류에서 나올 수 있는 경우의 수는 (의상의 개수 + 1)가 된다. (아예 그 옷 종류를 입지 않는 경우)\
경우의 수 : 이 모든 옷 종류의 경우의 수를 곱하고 모두 안 입은 경우 1을 빼주는 방법 사용
*/