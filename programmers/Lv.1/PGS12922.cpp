// PGS 12922. 수박수박수박수박수박수? / Lv.1
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string water = "수박";
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++) {
            answer += water;
        }
    }
    
    else {
        for (int i = 0; i < n / 2; i++) {
            answer += water;
        }
        answer += "수";
    }
    return answer;
}