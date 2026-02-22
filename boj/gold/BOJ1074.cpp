// BOJ 1074. Z / G5
#include <iostream>
#include <vector>

using namespace std;

int N, r, c;
int num = 0;
void wz(int x, int y, int size) {
    if (size == 1) return;

    int half = size / 2;
    int quad = half * half;

    if (r < x + half && c < y + half) {
        wz(x, y, half);
    }
    else if (r < x + half && c >= y + half) {
        num += quad;
        wz(x, y + half, half);
    }
    else if (r >= x + half && c < y + half) {
        num += 2 * quad;
        wz(x + half, y, half);
    }
    else {
        num += 3 * quad;
        wz(x + half, y + half, half);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> r >> c;

    int size = 1 << N;

    wz(0, 0, size);

    cout << num << "\n";
}

/*
r, c를 기준으로 어떤 사분면에 존재하냐에 따라 미리 앞에 있는 숫자들을 체크해서 r, c 좌표에 찍힐 숫자를 출력
*/


// 이차원 벡터를 직접 채우면서 진행 -> 메로리 초과
/*
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> zmap;
int r, c;
int num = 0;
void wz(int x, int y, int size) {
    if (size == 1) {
        zmap[x][y] = num;
        num++;
        return;
    }

    int half = size / 2;

    wz(x, y, half);
    wz(x, y + half, half);
    wz(x + half, y, half);
    wz(x + half, y + half, half);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N >> r >> c;

    int size = 1 << N;

    zmap.assign(size, vector<int>(size, 0));

    wz(0, 0, size);

    cout << zmap[r][c] << "\n";
}
*/