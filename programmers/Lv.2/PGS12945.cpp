// PGS 12945. 피보나치 수 / Lv.2
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<long long> fibo(n + 1, 0);
    fibo[1] = 1;
    
    for (int i = 2; i <= n; i++){
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1234567;
    }
    
    return fibo[n];
}

/*
DP 활용해서 피보나치 수열 제작
피보나치 수열 자체로 제작할 경우 long long 타입으로 해도 범위 초과함
1234567로 나눈 나머지로 피보나치 수열을 제작해서 값 출력
*/