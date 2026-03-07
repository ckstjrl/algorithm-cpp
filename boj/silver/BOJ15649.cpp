// BOJ 15649. N과 M (1) / S3
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[10];
int visited[10] = { 0 };
void dfs(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            arr[depth] = i;

            dfs(depth + 1);

            visited[i] = 0;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    
    dfs(0);
}

/*
DFS + 백트래킹 사용
재귀함수를 계속 돌면서 visited를 통해 방문했는지 하지 않았는지를 통해 순열을 구현하고
출력 진행
*/