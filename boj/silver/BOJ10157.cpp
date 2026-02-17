// BOJ 10157. 자리배정 / S3
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> lay;
    int x = M;
    int y = N;
    int n = 0;
    while (x - 2 * n > 0 && y - 2 * n > 0) {
        int ea = 2 * (x - 2 * n) + 2 * (y - 2 * n) - 4;
        lay.push_back(ea);
        n++;
    }

    if (K > M * N) cout << 0 << "\n";
    else {
        int s = 0;
        int sum = 0;
        for (int i = 0; i < lay.size(); i++) {
            sum += lay[i];
            if (K <= sum){
                s = i;
                sum -= lay[i];
                break;
            }
        }
        int diff = K - sum;
        int ansx;
        int ansy;
        
        int part_one = M - 2 * s;
        int part_two = N + M - 4 * s - 1;
        int part_three = 2 * M + N - 6 * s - 2;
        int part_four = 2 * M + 2 * N - 8 * s - 4;

        if (diff <= part_one) {
            ansx = s + diff - 1;
            ansy = s;
        }
        else if (part_one < diff && diff <= part_two) {
            ansx = M - s - 1;
            ansy = diff - part_one + s;
        }
        else if (part_two < diff && diff <= part_three) {
            ansx = part_three + s - diff;
            ansy = N - s - 1; 
        }
        else {
            ansx = s;
            ansy = s + 1 + part_four - diff;
        }
        cout << ansy + 1 << " " << ansx + 1 << "\n";
    }
}

/*
모든 숫자를 채우면서 찾으면 어렵기 때문에 lay 벡터를 만들어서 1단 2단 3단... 이렇게 껍질에 들어갈 수 있는 개수를 넣음
lay 벡터의 요소를 하나씩 더하면서 K가 몇 번째 껍집에 들어 있는지 확인
K가 들어 있는 껍질을 찾고나서 K가 어디 들어 있는지 좌표를 찾는 과정 진행
채워지는 부분을 순서대로 part_one, two, three, four로 두고 4가지 경우로 나누어 찾음
이후 찾은 좌표는 0, 0에서부터 시작한 것이기 때문에 + 1 을 진행해주고
문제에서 요구한 좌표와 평상시 활용하는 이차원 배열의 좌표가 다르기 때문에 그에 맞게 수정하여 출력 진행
*/