// PGS 12953. N개의 최소공배수 / Lv.2
#include <string>
#include <vector>

using namespace std;


int GCD (int a, int b) {
    int r = 1;
    
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    while (a % b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    
    return b;
}

int LCM (int a, int b) {
    int g = GCD(a, b);
    return (a * b) / g;
}

int solution(vector<int> arr) {
    int lcm = 1;
    
    for (int i : arr) {
        lcm = LCM(lcm, i);
    }
    
    return lcm;
}

/*
N개의 최소공배수는 앞에서 부터 최소공배수를 구하고 최소공배수와 다음 요소의 최소공배수를 구하는 방법으로 구할 수 있음
최소공배수는 유클리드 호제법을 활용하여 최대공배수를 구하고 두 수의 곱을 최대공배수로 구하는 방식으로 구함
최대공배수, 최소공배수를 구하는 로직은 함수화로 구현
*/