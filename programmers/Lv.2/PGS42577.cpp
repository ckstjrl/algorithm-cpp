// PGS 42577. 전화번호 목록 / Lv.2
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i + 1].find(phone_book[i]) == 0) {
            answer = false;
            return answer;
        }
    }
    return answer;
}

/*
사전순으로 정렬하면 접두가 같은것 끼리 그룹화 되므로 i인덱스와 i+1 인덱스 서로 확인하면됨
예를 들어 전화번호 목록이 ["119", "1123", "1345", "119032"]인 경우
사전 순으로 정렬하게 되면 ["1123", "119", "119032", "1345"]이렇게 정렬되게 됨.
*/