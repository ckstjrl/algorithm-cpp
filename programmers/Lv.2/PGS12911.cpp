// PGS 12911. 다음 큰 숫자
#include <string>
#include <vector>

using namespace std;

int bi_one (int a) {
    int one_cnt = 0;
    while (a != 1){
        if (a % 2 != 0) {
            one_cnt++;
            a /= 2;
        }
        else a /= 2;
    }
    return one_cnt;
}

int solution(int n) {
    int answer = 0;
    int n_bi_one = bi_one(n);
    
    for(int i = n + 1; i <= 1000000; i++){
        int nxt_bi_one = bi_one(i);
    
        if (nxt_bi_one == n_bi_one) {
            answer = i;
            break;
        }
    }
    return answer;
}

/*
먼저 10진법을 2진법으로 변경하여 1의 개수를 리턴해주는 bi_one이라는 함수 제작

이후 n을 받아서 n의 2진법에서의 1의 개수를 저장하고
반복문을 통해 1씩 증가하면서 2진법에서의 1의 개수가 동일한 다음 큰 자연수를 찾으면 
break 출력
*/