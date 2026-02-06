// BOJ 30804. 과일 탕후루 / S2
#include <iostream>
#include <vector>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> tang(N);
    for(int i = 0; i < N; i++) {
        cin >> tang[i];
    }

    int fruit[10] = { 0 };
    int kind = 0;
    int l = 0;
    int maxlen = 0;

    for(int r = 0; r < N; r++){
        if(fruit[tang[r]] == 0) {
            kind++;
        }
        fruit[tang[r]]++;

        while (kind > 2) {
            fruit[tang[l]]--;
            if (fruit[tang[l]] == 0) {
                kind--;
            }
            l++;
        }
        maxlen = max(maxlen, r - l + 1);
    }
    cout << maxlen << "\n";
}

/*
문제를 읽으면서 앞 뒤로 뽑는다 해서 처음에는 deque 생각했으나
구현 과정에서 아니라는 것을 확인
두 개의 포인터를 활용해야 함
vector를 왼쪽에서 오른쪽으로 증가시키면서 종류가 2개 이상이 되면 왼쪽 부터 종류가 2개가 될때ㄷ까지 제거하고
이렇게 과일 종류가 2개 이하라는 조건을 만족할 때마다 탕후루의 길이를 max값과 비교하면서 값 출력

*/