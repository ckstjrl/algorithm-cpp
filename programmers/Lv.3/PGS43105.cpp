// PGS 43105. 정수 삼각형 / Lv.3
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int L = triangle.size();
    for (int i = L - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            triangle[i - 1][j] += max(triangle[i][j], triangle[i][j + 1]);
        }
    }
    answer = triangle[0][0];
    return answer;
}

/*
가장 큰 합을 구해야하기 때문에 DP 활용
아래서부터 위로 올라가는 방식으로 계산
만약 tri[3][1]이라면 아래에서 선택할 수 있는 수는 tri[4][1], tri[4][2] 두 수인데 둘중 큰 수를 합하면 되는 방식
*/