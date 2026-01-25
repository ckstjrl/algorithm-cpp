// BOJ 2609. 최대공약수와 최소공배수 / B1
#include <iostream>

using namespace std;

int GCD(int a, int b){
    int q = a / b;
    int r = a % b;

    if (r == 0) return b;
    
    return GCD(b, r);
}

int main(){
    int N, M;
    cin >> N >> M;

    int gcd = GCD(N, M);
    int lcm = (N * M) / gcd;

    cout << gcd << "\n" << lcm << "\n";
}


/*
유클리드 호제법을 활용하여 최대공약수를 만드는 재귀함수를 작성
main 함수에서 최대공약수를 구한 후
최소공배수 = N * M / 최대공약수 과정을 통하여 계산해 출력
*/