//출처: 백준 2992번 문제
//문제: 크면서 작은 수
//내용: Back Tracking, 순열
// 핵심은 "다음 순열이 있는가 없는가"로 판단 할 수 있다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

std::vector<int> arr;
int main()
{
	ios_base::sync_with_stdio(false);
	string X;
	cin >> X;

	bool flag = next_permutation(X.begin(), X.end());
	if (flag)
		cout << X << endl;
	else
		cout << "0" << endl;
	
	return 0;
}