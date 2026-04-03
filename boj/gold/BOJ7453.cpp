#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N), B(N), C(N), D(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    vector<int> AB;
    vector<int> CD;
    AB.reserve(N * N);
    CD.reserve(N * N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    long long answer = 0;
    int left = 0;
    int right = (int)CD.size() - 1;

    while (left < (int)AB.size() && right >= 0) {
        long long sum = (long long)AB[left] + CD[right];

        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            int abVal = AB[left];
            int cdVal = CD[right];

            long long abCount = 0;
            long long cdCount = 0;

            while (left < (int)AB.size() && AB[left] == abVal) {
                abCount++;
                left++;
            }

            while (right >= 0 && CD[right] == cdVal) {
                cdCount++;
                right--;
            }

            answer += abCount * cdCount;
        }
    }

    cout << answer << '\n';
}

/*
투포인터 활용
A + B의 모든 합을 배열에 저장 (N²개)
C + D의 모든 합도 배열에 저장 (N²개)
두 배열을 정렬
투 포인터로
AB[i] + CD[j] == 0 인 경우를 찾음
*/