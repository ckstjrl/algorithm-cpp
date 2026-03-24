// BOJ 1722. 순열의 순서 / G5
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    vector<long long> fact(N + 1, 1);
    for (int i = 1; i < N + 1; i++) {
        fact[i] = fact[i - 1] * i;
    }

    vector<int> num(N);
    for (int i = 0; i < N; i++) {
        num[i] = i + 1;
    }
    
    int c;
    cin >> c;
    
    if (c == 1) {
        long long E;
        cin >> E;
        E--;

        for (int i = 0; i < N; i++) {
            long long block = fact[N - 1 - i];
            long long idx = E / block;
            E %= block;

            cout << num[idx] << " ";
            num.erase(num.begin() + idx);
        }
    }
    
    else if (c == 2) {
        vector<int> arr(N);
        for (int i = 0 ; i < N; i++) {
            cin >> arr[i];
        }
        
        long long order = 1;

        for (int i = 0; i < N; i++) {
            int idx = 0;
            while (num[idx] != arr[i]) {
                idx++;
            }

            order += (long long)idx * fact[N - 1 - i];
            num.erase(num.begin() + idx);
        }
        cout << order << "\n";
    }
}

/*
 이 문제는 순열을 직접 모두 만들어서 구하면 안됨.
 N이 최대 20이므로 20!은 너무 커서 완전탐색으로는 불가능
 따라서 팩토리얼을 이용해서 순열의 순서와 k번째 순열을 바로 구해야 함

 1. k번째 순열 구하기 (c == 1)
 - 숫자 1 ~ N을 num 벡터에 넣어둔다.
 - 현재 자리에서 하나의 숫자를 고르면, 남은 숫자로 만들 수 있는 경우의 수는
   (남은 개수)! 이다.
 - 이를 block = fact[N - 1 - i] 로 둔다.
 - k가 몇 번째 묶음에 속하는지 idx = k / block 으로 구한다.
 - num[idx]가 현재 자리에 들어갈 숫자이다.
 - 그 숫자를 출력하고, num에서 제거한다.
 - 이후 k는 현재 묶음 내부에서 다시 계산해야 하므로 k %= block 처리한다.
 - 문제의 순서는 1번부터 시작하므로 계산 편의를 위해 처음에 k-- 해서 0-based로 바꾼다.

 2. 주어진 순열의 순서 구하기 (c == 2)
 - 숫자 1 ~ N을 num 벡터에 넣어둔다.
 - 순열을 앞자리부터 확인한다.
 - 현재 자리의 값 arr[i]가 num에서 몇 번째(idx)에 있는지 찾는다.
 - arr[i]보다 작은 숫자들이 앞에 idx개 있다는 뜻이므로,
   그 숫자들로 시작하는 순열의 개수 idx * fact[N - 1 - i] 를 순서에 더한다.
 - 현재 사용한 숫자는 num에서 제거한다.
 - 순서는 1번부터 시작하므로 order의 초기값은 1이다.
 */