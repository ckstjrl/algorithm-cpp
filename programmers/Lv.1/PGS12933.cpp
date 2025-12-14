/* PSG.12933. 정수 내림차순으로 배치하기 / Lv.1 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> arr;
    while (n) {
        arr.emplace_back(n%10);
        n /= 10;
    }
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < arr.size(); i++) {
        answer += arr[i]*pow(10, i);
    }
    return answer;
}

/*
while문을 통해 n이 0이 되기 전까지 반복
n을 10으로 나눈 나머지를 vector에 넣고 n을 10으로 나눈값으로 최신화 진행
vector을 오름차순 정렬
vector에서 하나씩 뽑아서 10의 i승을 곱해 더해주며 정렬된 수를 만들어 풀이
*/