// PGS 12981. 영어 끝말잇기 / Lv.2
#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> used;
    used.insert(words[0]);
    
    for(int i = 1; i < words.size(); i++) {
        if (words[i - 1].back() != words[i][0] || used.count(words[i])) {
            return { (i % n) + 1, i / n + 1 };
        }
        
        used.insert(words[i]);
    }
    
    return { 0, 0 };
}

/*
사용한 단어인지, 앞단어의 뒤 글자와 현재 단어의 앞글자가 동일한지 확인
헤당 단어가 틀린경우 몇 번째 사람이, 몇 번째 딘어에서 틀린건지 출력
첫 번째 정답이 깔끔하지 않고 불필요한 로직이 있어 set 자료구조 활용해서 사용한 단어를 체크하는 방향으로 시간 복잡도와 코드 가독성 증대
*/

// 첫 번째 정답
/*
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    int wrong = 0;
    
    for (int i = 1; i < words.size(); i++) {
        bool same_w = false;
        for (int j = 0; j < i; j++) {
            if (words[i] == words[j]) {
                same_w = true;
                break;
            }
        }
        if (same_w) {
            wrong = i;
            break;
        }
        else {
            if (words[i - 1][words[i - 1].length() - 1] != words[i][0]) {
                wrong = i;
                break;
            }
        }
    }
    if (wrong) {
        answer[0] = (wrong + 1) % n;
        if (answer[0] == 0) {
            answer[0] = n;
        }
        answer[1] = wrong / n + 1;    
    }
    else {
        answer[0] = 0;
        answer[1] = 0;
    }

    return answer;
}
*/

