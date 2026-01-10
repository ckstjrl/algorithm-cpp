// PGS 42842. 카펫 / Lv.2

#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;

    for (int h = 3; h*h <= total; h++) {
        if (total % h != 0) continue;
        int w = total / h;
        if ((w - 2) * (h - 2) == yellow) {
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }
    return answer;
}

/*
처음 문제를 풀이할 때 cmath를 사용해서
x + y = yellow, 2x + 2y + 4 = brown 이 두식을 활용해 방정식을 활용해 문제를 풀이 진행
이 경우 sqrt를 사용하게 되면 제대로된 값이 나오지 않는 경우가 있기때문에 방법 수정

최종적인 너비 높이를 통해 구하기
너비 곱하기 높이는 전체 칸의 개수
전체 칸의 개수가 높이나 너비로 나누어떨어지지 않는다면 불가능
높이를 증가시키면서 (w - 2) * (h - 2) == yellow라면 바로 출력
*/