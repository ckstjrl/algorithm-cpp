#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mapping[101] = { 0 };

int main(){
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N + M; i++) {
        int a, b;
        cin >> a >> b;
        mapping[a] = b;
    }

    queue<pair<int, int>> q;
    int visited[101] = { 0 };
    q.push({1, 0});
    visited[1] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (x == 100) {
            cout << cnt << "\n";
            break;
        }

        for(int i = 1; i < 7; i++){
            int nxt = x + i;
            if (nxt <= 100) {
                if (mapping[nxt] != 0) {
                    nxt = mapping[nxt];
                }
                if (visited[nxt] != 1) {
                    visited[nxt] = 1;
                    q.push({nxt, cnt + 1});
                }
            }
        }
    }
}

/*
뱀과 사다리로 연결된 지점들을 저장할 방법으로 mapping 배열을 생성하고, 뱀이나 사다리 시작 칸을 인덱스로 두고 도착 칸을 값으로 하는 배열 저장
이후 주사위 굴려서 움직이는 로직은 BFS로 구현
mapping[nxt]가 0인 경우 뱀이나 사다리가 없기때문에 주사위 크기를 더한 값이 다음 칸이 되고,
0이 아닌 경우는 뱀이나 사다리가 연결되어있기때문에 해당 인덱스에 존재하는 값의 칸이 다음 칸이 되는 로직으로 구현
진행 후 현재 칸이 100이 되면 주사위를 굴린 횟수를 출력
*/