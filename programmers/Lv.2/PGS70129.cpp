// PGS 70129. 이진 변환 반복하기 / Lv.2
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int remove_cnt = 0;

    while (s != "1"){
        cnt ++;
        int one_cnt = 0;

        for (int i = 0; i < s.length(); i++){
            if (s[i] == '1'){
                one_cnt ++;
            }
        }

        remove_cnt += s.length() - one_cnt;
        
        vector<string> bi;
        while(one_cnt > 1){
            if (one_cnt % 2 == 0){
                bi.push_back("0");
                one_cnt /= 2;
            }

            else {
                bi.push_back("1");
                one_cnt /= 2;
            }
        }
        bi.push_back("1");

        s.clear();
        for (int j = bi.size()-1; j >= 0; j--){
            s += bi[j];
        }
    }
    answer.push_back(cnt);
    answer.push_back(remove_cnt);
    return answer;
}

/*
cnt는 이진변환을 반복한 횟수, remove_cnt는 지워진 0의 개수를 의미함.
while(s == "1")을 활용해 s가 1이 될때까지 진행하고 while문 내부를 반복하는 횟수 = cnt가 됨.
while 반복문 안에서
1. 1의 개수 세기, 1의 개수를 세서 one_cnt에 넣어줌
2. 지워진 0의 개수 = 원래 s의 길이 - 1의 개수
3. 1의 개수가 곧 새로운 이진수의 길이 -> 이를 활용해 2로 계속 나누어 나머지를 vector에 저장하고 뒤에서 부터 읽으면 새로운 s가 된다.
이렇게 3과정을 진행함
이후 cnt와 remove_cnt를 vector에 넣어 return
*/