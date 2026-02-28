// BOJ 1043. 거짓말 / G4
#include <iostream>
#include <vector>
#include<queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int k;
    cin >> k;

    vector<int> initialT(k);
    for(int i = 0; i < k; i++) {
        cin >> initialT[i];
    }

    vector<vector<int>> party(M); // party에 참가한 사람 번호 벡터에 넣음
    vector<vector<int>> peopleParty(N + 1); // idx 사람이 참가한 party를 벡터에 넣음
    
    for (int i = 0; i < M; i++) {
        int pn;
        cin >> pn;
        party[i].resize(pn);
        for (int j = 0; j < pn; j++) {
            int p;
            cin >> p;
            party[i][j] = p;
            peopleParty[p].push_back(i);
        }
    }

    vector<int> know(N + 1, 0); // 진실을 아는 사람인지 여부
    vector<int> knowParty(M, 0); // 진실을 아는 사람이 참여한 파티인지 여부

    queue<int> q;
    for (int p : initialT) {
        if (!know[p]) {
            know[p] = 1; // 초기값에 있는 사람을 진실을 아는 사람에 체크
            q.push(p); // 큐에 넣어줌
        }
    }

    // BFS
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        
        for (int pp : peopleParty[p]) { // 진실을 아는 사람이 참여한 파티를 순회
            if (knowParty[pp]) continue; // 이미 진실을 아는 사람이 참여한 파티라고 체크되어 있으면 continue
            knowParty[pp] = 1; // 아니라면 일단 진실을 아는 사람이 참여했다고 체크

            for (int member : party[pp]) { // 진실을 아는 사람이 참여한 파티의 멤버 순회
                if (!know[member]) { // 진실은 아는 사람이 아닌 경우
                    know[member] = 1; // 진실을 안다고 체크한 후
                    q.push(member); // 큐에 추가
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < M; i++) {
        if (!knowParty[i]) ans++; // 진실을 아는 사람이 참여한 파티가 아닌 파티만 count해서 출력
    }

    cout << ans << "\n";
}