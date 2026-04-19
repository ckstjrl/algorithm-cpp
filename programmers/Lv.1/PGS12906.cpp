// PGS 12906. 같은 숫자는 싫어 / Lv.1
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int tmp = 10;
    for (int a : arr) {
        if (a != tmp) {
            answer.push_back(a);
            tmp = a;
        }
    }

    return answer;
}