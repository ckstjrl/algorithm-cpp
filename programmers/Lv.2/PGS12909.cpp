// PGS 12909. 올바른 괄호 / Lv.2
#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for(char i : s){
        if(i == '(') st.push(i);

        else{
            if (st.empty()){
                answer = false;
                break;
            }

            else{
                if (st.top() == '('){
                    st.pop();
                }

                else{
                    answer = false;
                    break;
                }
            }
        }
    }
    if(!st.empty()) answer = false;

    return answer;
}

/*
자료구조 stack 활용
(면 그냥 stack에 넣고
)면 stack이 비어있으면 false, stack.top()이 (가 아니면 false, stack.top()이 (이면 pop
한 이후
반복문 종료 후 stack이 비어 있지 않으면 false
처리하는 방식으로 문제 풀이
*/