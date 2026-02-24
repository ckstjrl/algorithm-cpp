// PGS 12985. 예상 대진표 / Lv.2
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    a -= 1;
    b -= 1;
    while (a != b) {
        a /= 2;
        b /= 2;
        answer++;
    }
    
    return answer;
}

/*
간단하게 생각해서 2로 나눈 값이 동일해지면 둘이 경쟁한 것이 된다
예를 들어 n = 16, a = 3, b = 11 이라고 해보자
0조 부터 센다고 했을 때
1번째 경기 : a는 1조, b는 5조에 편성
2번째 경기 : a는 0조, b는 2조에 편성
3번째 경기 : a는 0조, b는 1조에 편성
4번째 경기 : a, b 모두 0조에 편성

이렇게 4번째 경기에서 두 팀이 만날 수 있다.
*/