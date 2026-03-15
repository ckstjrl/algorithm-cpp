// BOJ 11727. 2xn 타일링 2 / S3
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long a = 1;
    long long b = 3;
    long long c;

    if (n == 1) {
        cout << a << "\n";
    }
    else if (n == 2) {
        cout << b << "\n";
    }
    else {
        int cnt = 2;
        while (cnt != n) {
            c = (2 * a + b) % 10007;
            a = b;
            b = c;
            cnt++;
        }
        cout << c << "\n";
    }
}

/*
DP 활용
타일링 문제는 DP 점화식을 구하면 되는 문제
점화식은 dp[i] = 2 * dp[i - 2] + dp[i - 1]
벡터로 문제풀이를 진행할까 고민하다 메모리를 최소로 사용하는 방법을 고민함
벡터를 이용해서 3개의 요소만을 사용해서 구해도 괜찮지만
3개의 요소만 사용할거면 벡터나 배열을 사용하는 것보다 long long 변수를 사용하여 구할 수도 있다는 생각에
3개의 변수를 사용해서 답 출력
*/