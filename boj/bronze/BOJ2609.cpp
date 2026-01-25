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
