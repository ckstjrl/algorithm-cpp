// PGS 12973. 짝지어 제거하기 / Lv.2
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> comp;
    int answer = 0;
    for(char i : s){
        if(!comp.empty() && i == comp.top()){
            comp.pop();
        }
        else comp.push(i);
    }
    
    if(comp.empty()) answer = 1;
    

    return answer;
}

/*
자료구조 stack 활용
스택이 비어 있는 경우 s의 한 글자를 집어 넣고.
스택이 비어 있지 않은데 stack의 top이 s와 동일하지 않아도 넣고,
스택이 비어있지 않고 stack의 top이 동일하다면 pop

예시
 abba
 i          stack
 a          a -> 넣어줌
 b          a, b -> 넣어줌
 b          a -> b 뽑아감
 a          - -> a 뽑아감
결국 stack은 empty
*/