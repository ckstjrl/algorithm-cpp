// BOJ 1991. 트리 순회 / S1
#include <iostream>
#include <vector>

using namespace std;
vector<char> root;
vector<int> left_;
vector<int> right_;

void preorder(int node) {
    if (node == 0) return;
    cout << root[node];
    preorder(left_[node]);
    preorder(right_[node]);
}

void inorder(int node) {
    if (node == 0) return;
    inorder(left_[node]);
    cout << root[node];
    inorder(right_[node]);
}

void postorder(int node) {
    if (node == 0) return;
    postorder(left_[node]);
    postorder(right_[node]);
    cout << root[node];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    root.assign(N+1, '.');
    left_.assign(N+1, 0);
    right_.assign(N+1, 0);
    for (int i = 0; i < N; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        int idx = a - 'A' + 1;
        int l = 0;
        int r = 0;
        if (b != '.') {
            l = b - 'A' + 1;
        }
                
        if (c != '.') {
            r = c - 'A' + 1;
        }
        
        
        root[idx] = a;
        left_[idx] = l;
        right_[idx] = r;
    }

    preorder(1);
    cout << "\n";
    inorder(1);
    cout << "\n";
    postorder(1);
}

/*
root는 따로 char 형태로 저장하고
왼쪽 자식, 오늘쪽 자식은 숫자 형태로 저장하여 재귀호출에서 편하게 활용
재귀함수를 제작하여 제귀 호출과 출력의 위치를 변경하여 선위 순회, 중위 순회, 후위 순회를 구현
*/