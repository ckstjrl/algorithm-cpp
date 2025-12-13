/* PGS 12944. 평균 구하기 / Lv. 1 */

#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    double total = 0;
    for (int i = 0; i < arr.size(); i++) {
        total += arr[i];
    }
    answer = total/arr.size();
    return answer;
}

/*
평균의 자료형이 double임
C언어에서는 int 나누기 int의 경우 int가 나옴
이것을 고려해서
배열 요소의 총합인 total을 double로 설정하고 계산
for 문으로 arr 사이즈 만큼 반복을 돌리면서 요소를 total에 더하면서 총 합 구함
total을 arr 사이즈로 나누어주면 평균 구할 수 있음
이 방식으로 문제 풀이
*/