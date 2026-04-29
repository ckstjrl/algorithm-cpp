// PGS 12935. 제일 작은 수 제거하기 / Lv.1
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {

    if (arr.size() == 1) {
        return { -1 };
    }
    
    int min_idx = min_element(arr.begin(), arr.end()) - arr.begin();
    
    arr.erase(arr.begin() + min_idx);
    
    return arr;
}