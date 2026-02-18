// BOJ 11722. 가장 긴 감소하는 부분 수열 / S2
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> ans;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if (ans.empty() || ans.back() > num) {
            ans.push_back(num);
        }
        else if (ans.size() == 1 && ans[0] < num) {
            ans[0] = num;
        }

        else {
            int l = 0;
            int r = ans.size();

            while (l < r) {
                int m = (l + r) / 2;
                if (ans[m] > num) {
                    l = m + 1;
                }
                else {
                    r = m;
                }
            }
            ans[r] = num;
        }
    }

    cout << ans.size() << "\n";
}

/*
가장 긴 증가하는 부분 수열 문제와 비슷한 방식으로 문제 풀이 진행
감소하는 수열이므로 해당 인덱스의 숫자가 num보다 크다면 l을 증가시키는 방향으로 이분탐색 진행 후 최신화
*/