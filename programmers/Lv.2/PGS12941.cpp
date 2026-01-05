// PGS12941. 최솟값 만들기 / Lv.2
#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int len = A.size();
    
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    
    for (int i = 0; i < len; i++){
        answer += A[i] * B[i];
    }

    return answer;
}

/*
두 벡터의 요소 곱의 합의 최솟값은 A의 작은 것과 B의 큰 것이 서로 곱한것을 더하면 됨.
A는 오름차순 정렬, B는 내림차순 정렬 진행하여
같은 index끼리 곱해서 answer에 합해줌.
*/