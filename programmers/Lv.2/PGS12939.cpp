// PGS12939. 최댓값과 최솟값

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    vector<int> v;
    int x;
    while (ss >> x){
        v.push_back(x);
    }
    int min_v = *min_element(v.begin(), v.end());
    int max_v = *max_element(v.begin(), v.end());
    
    answer = to_string(min_v) + " " + to_string(max_v);
    
    return answer;
}

/*
sstream을 활용하여 " "으로 구분되어 있는 int를 받아서 vector에 넣고
최댓값 최솟값을 찾아 출력
*/