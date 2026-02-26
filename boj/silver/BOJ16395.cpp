// BOJ 16395. 파스칼의 삼각형 / S5
#include <iostream>

using namespace std;

long long solution(int n, int r) {
    long long ans = 1;
    r = min(r, n - r);
    for (int i = 1; i <= r; i++) {
        ans = ans * (n - r + i) / i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;

    cout << solution(N - 1, K - 1) << "\n";
}

/*
이 문제의 답을 구할 수 있는 방법 3가지를 생각해봄
1. 조합 활용
2. 1차원 배열로 파스칼 삼각형 구현
3. 2차원 배열로 파스칼 삼각형 구현

1번의 경우 시간 복잡도 O(k), 메모리 O(1)
2번의 경우 시간 복잡도 O(N^2), 메모리 O(N)
3번의 경우 시간 복잡도 O(N^2), 메모리 O(N^2)

시간 복잡도, 메모리 모두 유리한 1번 조합 활용하는 방법으로 구함

solution 함수를 통해 조합 식을 풀이 진행
overflow 문제 방지를 위해 long long 타입 활용
처음에는 반복문 내부 식을
ans *= (n - r + i) / i;
이렇게 작성했는데 이 경우 나머지가 0이 아니기 때문에 손실 발생
따라서, 
ans = ans * (n - r + i) / i;
로 식 변경하여 풀이
*/