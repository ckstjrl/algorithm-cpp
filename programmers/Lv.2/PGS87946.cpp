// PGS 87946. 피로도 / Lv.2
#include <string>
#include <vector>

using namespace std;

int max_cnt = 0;
vector<int> visited;

void dfs(int k, int cnt, vector<vector<int>> dungeons) {
    if (cnt > max_cnt) {
        max_cnt = cnt;
    }
    
    for (int i = 0; i < dungeons.size(); i++) {
        if (visited[i] == 0 && dungeons[i][0] <= k) {
            visited[i] = 1;
            dfs(k - dungeons[i][1], cnt + 1, dungeons);
            visited[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    visited.assign(dungeons.size(), 0);
    dfs(k, 0, dungeons);
    
    return max_cnt;
}

/*
완전탐색이므로 DFS활용
현재 피로도로 갈 수 있는 던전에 찾아 들어가는 방식으로 BFS 수행
재귀 중에 cnt가 max_cnt보다 커지면 max_cnt를 최신화 해주는 방법으로 진행
*/