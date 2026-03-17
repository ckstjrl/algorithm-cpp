// BOJ 2166. 다각형의 면적 / G5
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<long long, long long>> axis(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        axis[i] = { x, y };
    }

    long long sum = 0;

    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        sum += axis[i].first * axis[j].second;
        sum -= axis[i].second * axis[j].first;
    }
    double S = abs(sum) / 2.0;

    cout << fixed << setprecision(1) << S << "\n";
    
}

/*
다각형 넓이 구할 때 신발끈 공식 활용해서 문제 풀이 진행
#include <iomanip>
cout << fixed << setprecision(1) << S << "\n";
소숫점 1번째자리까지 나올 수 있게 반올림해주는 방식
*/