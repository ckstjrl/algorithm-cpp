// BOJ 15650. N과 M (2) / S3
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[10];

void dfs(int s, int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    for (int i = s; i <= N; i++) {
        arr[depth] = i;
        dfs(i + 1, depth + 1);
    }
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    
    dfs(1, 0);
}

/*
N과 M (1)문제와 유사하지만
이 문제의 경우 순서가 변경되는 것은 출력하지 않고 오름차순으로 되어있는 수열만 출력 진행
-> 조합으로 생각
1번 문제와 다르게 visited가 필요 없고 dfs 함수의 매개변수에 현재 찍힌 숫자를 s로 입력하므로
앞에 현재보다 큰 숫자가 오지 않도록 설계 진행
*/