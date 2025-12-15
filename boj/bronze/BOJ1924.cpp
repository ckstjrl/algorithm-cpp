// BOJ 1924. 2007년 / B1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int date[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int M, D;
	cin >> M >> D;
	
	int total = 0;
	for (int i = 0; i < M; i++) {
		total += date[i];
	}
	total += (D - 1);

	string day[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	cout << day[total % 7] << '\n';
}

/*
date arr에 0번 인덱스를 0으로 비우고 월별 날짜를 적어 놓음
total이라는 변수에 input으로 받은 월일을 기준으로 몇 일이 지났는지 계산
0번 인덱스를 월요일 기준으로 arr작성
total을 7로 나눈 나머지로 요일 출력
*/