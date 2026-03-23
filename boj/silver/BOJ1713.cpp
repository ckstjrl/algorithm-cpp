// BOJ 1713. 후보 추천하기 / S1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> frame;

    int cnt[101] = { 0 };
    int time[101] = { 0 };
    int in[101] = { 0 };

    for (int i = 0; i < M; i++) {
        int s;
        cin >> s;
        
        if (in[s] != 0) {
            cnt[s]++;
        }
        else {
            if (frame.size() < N) {
                frame.push_back(s);
                in[s] = 1;
                cnt[s] = 1;
                time[s] = i;
            }

            else {
                int remove = frame[0];

                for (int j = 0; j < frame.size(); j++) {
                    int cur = frame[j];

                    if (cnt[cur] < cnt[remove]) {
                        remove = cur;
                    }
                    else if (cnt[cur] == cnt[remove]) {
                        if (time[cur] < time[remove]) {
                            remove = cur;
                        }
                    }
                }

                in[remove] = 0;
                cnt[remove] = 0;

                frame.erase(find(frame.begin(), frame.end(), remove));

                frame.push_back(s);
                in[s] = 1;
                cnt[s]++;
                time[s] = i;
            }
        }
    }

    sort(frame.begin(), frame.end());

    for (int f : frame) {
        cout << f << " ";
    }
}

/*
frame에 후보를 넣고
cnt는 후보로 뽑힌 횟수
time은 후보로 뽑힌 순서 -> 작을수록 오래된 후보
in은 frame에 들어있는지 아닌지 확인하는 배열

4개의 배열을 활용해 문제의 1~5까지 구현
*/