#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> rnk;

int find_root(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_root(parent[x]);  // 경로 압축
}

void unite(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a == b) return;

    // 랭크 기반 union
    if (rnk[a] < rnk[b]) swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) rnk[a]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    parent.resize(N + 1);
    rnk.assign(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    while (M--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0) {
            unite(a, b);
        } else {
            cout << (find_root(a) == find_root(b) ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
