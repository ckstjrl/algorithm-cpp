/* BOJ 4344. 평균은 넘겠지 / B1*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        int total = 0;

        vector<int> v(N);
        for (int j = 0; j < N; j++) {
            cin >> v[j];
            total += v[j];
        }
        int avg = total / N;
        float over_student = 0;
        for (int a = 0; a < N; a++) {
            if (v[a] > avg) {
                over_student += 1;
            }
        }
        float over_p = (over_student / N) * 100;
        cout << fixed << setprecision(3) << over_p << "%" << "\n";
    }
}

/*
1. Testcase 수 N 입력 받고 for문 반복
2. 숫자 입력 중 맨 첫번 째로 인원 수 받고 for 문 반복해 vector에 점수 저장하면서 총합 구함
3. avg 값을 구하고 그 이상인 점수가 있는지 다시 vector 반복 확인
4. 평균 초과하는 인원 수 구한 후 전체 인원으로 나누고 100 곱함
5. 소수점 3번째자리까지 표현하기 위해 #include <iomanip> -> cout << fixed << setprecision(3) << 값 활용
*/