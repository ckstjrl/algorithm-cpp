// BOJ 9019. DSLR / G4
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int D (int n) {
    return 2 * n % 10000;
}

int S (int n) {
    int s = n - 1;
    if (s < 0) {
        s = 9999;
    }

    return s;
}

int L (int n) {
    int a = n % 1000;
    int b = n / 1000;
    return a * 10 + b;
}

int R (int n) {
    int a = n / 10;
    int b = n % 10;
    return b * 1000 + a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        vector<int> visited(10001, 0);
        vector<int> parent(10001, 0);
        vector<char> how(10001);

        queue<int> q;
        q.push(A);
        visited[A] = 1;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (cur == B) break;

            int nxt;

            nxt = D(cur);
            if (visited[nxt] == 0) {
                visited[nxt] = 1;
                parent[nxt] = cur;
                how[nxt] = 'D';
                q.push(nxt);
            }

            nxt = S(cur);
            if (visited[nxt] == 0) {
                visited[nxt] = 1;
                parent[nxt] = cur;
                how[nxt] = 'S';
                q.push(nxt);
            }

            nxt = L(cur);
            if (visited[nxt] == 0) {
                visited[nxt] = 1;
                parent[nxt] = cur;
                how[nxt] = 'L';
                q.push(nxt);
            }

            nxt = R(cur);
            if (visited[nxt] == 0) {
                visited[nxt] = 1;
                parent[nxt] = cur;
                how[nxt] = 'R';
                q.push(nxt);
            }
        }

        string ans = "";
        int cur = B;
        while(cur != A) {
            ans += how[cur];
            cur = parent[cur];
        }

        for (int i = ans.length() - 1; i >= 0; i--) {
            cout << ans[i];
        }
        cout << "\n";
    }
}

/*
BFS 활용
DSLR 함수를 각각 구현하고
cur을 넣었을 때 함수의 값을 nxt로 하고
visited 표시, nxt의 부모는 cur, 사용한 함수의 char 저장
이 3가지 벡터를 통해
B -> A 방향으로 답을 찾음
그렇게 나온 답은 원하는 답의 역순이므로
for문을 통해 역순 출력
*/