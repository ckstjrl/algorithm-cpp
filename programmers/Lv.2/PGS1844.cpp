// PGS 1844. 게임 맵 최단거리 / Lv.2

#include<vector>
#include <queue>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int solution(vector<vector<int>> maps)
{
    int N = maps.size();
    int M = maps[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> visited (N, vector<int>(M, 0));
    
    q.push({ 0, 0 });
    visited[0][0] = 1;
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        
        q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && visited[nx][ny] == 0 && maps[nx][ny] == 1) {
                q.push({ nx, ny });
                visited[nx][ny] = visited[cx][cy] + 1;
            }
        }
    }
    
    if (visited[N - 1][M - 1] == 0) {
            return -1;
    }

    return visited[N - 1][M - 1];
}

/*
전형적인 BFS 문제
*/