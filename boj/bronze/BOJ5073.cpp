// BOJ 5073. 삼각형과 세 변 / B3
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> tri(3);
    while (1) {
        for (int i = 0; i < 3; i++) {
            cin >> tri[i];
        }

        if (tri[0] == 0 && tri[1] == 0 && tri[2] == 0) {
            break;
        }

        sort(tri.begin(), tri.end());

        if (tri[2] >= tri[0] + tri[1]) {
            cout << "Invalid" << "\n";
            continue;
        }

        else {
            
            if (tri[0] == tri[1] && tri[1] == tri[2]) {
                cout << "Equilateral" << "\n";
                continue;
            }
            
            else if (tri[0] == tri[1] || tri[1] == tri[2]) {
                cout << "Isosceles" << "\n";
                continue;
            }
            else {
                cout << "Scalene" << "\n";
                continue;
            }
        }
    }
}

/*
먼저 삼각형이 될 수 없는 case를 분리한 후
정삼각형 case
이등변삼각형 case
이외에는 Scalene 삼각형 case 순으로 if절로 분리 진행
*/