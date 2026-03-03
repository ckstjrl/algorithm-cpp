// PGS 12949. 행렬의 곱셈 / Lv.2
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int r = arr1[0].size();
    int c = arr1.size();
    int p = arr2[0].size();
    vector<vector<int>> answer(c, vector<int>(p));

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < r; k++) {
                answer[i][j] += (arr1[i][k] * arr2[k][j]);
            }
        }
    }
    return answer;
}

/*
arr1의 행크기, 열크기, arr2의 열 크기를 활용 + 3중 for문으로 행렬 곱샘 구현
*/