// PGS 76502. 괄호 회전하기 / Lv.2
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int L = s.length();
    
    for (int i = 0; i < L; i++) {
        stack<char> st;
        bool ok = true;
        int n = 0;        
        while (n != L) {
            int idx = i + n;
            if (idx < L) {
                if (s[idx] == '(' || s[idx] == '{' || s[idx] == '[') {
                    st.push(s[idx]);
                    n++;
                }
                
                else {
                    if (st.empty()) {
                        ok = false;
                        break;
                    }
                    
                    if ((s[idx] == ')' && st.top() != '(') ||
                       (s[idx] == '}' && st.top() != '{') ||
                       (s[idx] == ']' && st.top() != '[')) {
                        ok == false;
                        break;
                    }
                    
                    else {
                        st.pop();
                        n++;
                    }
                }
            }
            
            else {
                idx = idx - L;
                if (s[idx] == '(' || s[idx] == '{' || s[idx] == '[') {
                    st.push(s[idx]);
                    n++;
                }
                
                else {
                    if (st.empty()) {
                        ok = false;
                        break;
                    }
                    
                    if ((s[idx] == ')' && st.top() != '(') ||
                       (s[idx] == '}' && st.top() != '{') ||
                       (s[idx] == ']' && st.top() != '[')) {
                        ok == false;
                        break;
                    }
                    
                    else {
                        st.pop();
                        n++;
                    }
                }
            }
        }
        if (!st.empty() && ok) ok = false;
        
        if (ok) answer++;
    }
    return answer;
}

/*
스택으로 괄호 검사 진행
여기서 괄호 검사 시작 부분이 한 칸씩 뒤로 간다는 부분과
인덱스로 검사시 out of index가 발생할 수 있는 부분을 고려해서 로직 구성
*/