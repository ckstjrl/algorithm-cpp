// BOJ 4779. 칸토어 집합 / S3
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> arr;

void sol(long long start, long long size) {
    if (size < 3) {
        return;
    }
    
    for (long long i = start + size / 3; i < start + (2 * size) / 3; i++) {
        arr[i] = 0;
    }

    sol(start, size / 3);
    sol(start + (2 * size) / 3, size / 3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N) {
        long long len = pow(3, N);
        arr.assign(len, 1);

        sol(0, len);

        for (int a : arr) {
            if (a == 1) {
                cout << "-";
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

/*
재귀함수 활용
stzrt지점과 size를 활용해서 가운데를 0으로 만들고
왼쪽 부분
오른쪽 부분
이렇게 진행하는 방식으로 문제 풀이
*/