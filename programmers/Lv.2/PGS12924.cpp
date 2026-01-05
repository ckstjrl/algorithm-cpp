// PGS 12924. 숫자의 표현 / Lv.2
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int k = 0; k * (k + 1) < 2 * n; k++){
        int xu = 2 * n - k * (k + 1);
        if (xu < 0) continue;
        
        if (xu % (2 * (k + 1)) == 0){
            int x = xu / 2 * (k + 1);
            if(x >= 1) answer++;
        }
    }
    return answer;
}

/*
수식으로 구현
일단
n = x + (x+1) + ... + (x+k) 형식으로 표현할 수 있어야 함
정리하면 
x = (2n - k(k+1)) / 2(k + 1) 형식으로 나옴
여기서 x는 무조건 자연수!
이것을 활용해
x > 0 으로 k범위를 구하면 k(k+1) < 2n
x가 존재할 조건식을 만들면
일단 분모는 무조건 양수 이므로 분자가 양수이어야함
1. int xu = 2 * n - k * (k + 1); 분자를 변수 xu에 넣음
2. xu 가 음수라면 continue
3. xu 가 분모 2(k+1)로 나누어 떨어지고 x >= 0 이면 answer++
*/