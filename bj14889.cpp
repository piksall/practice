//출처: 백준 14889
//문제: 스타트와 링크
//내용: Back Tracking
// 1. N/2개의 숫자를 정함
// 2. N/2개의 배열 arr1, arr2에 대하여 각각의 S_ij 합을 구함
// 3. 차이를 구해보고 최솟값일 경우 갱신
// 4. 그렇지 않은경우 패스
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<std::vector<int>> arr;
int minn = 999999;
int N;

/// target = 목표치
/// num = 현재 추가하고자 할 목표 인덱스
/// arr1 = 현재 배열
void f_recur(int target, int num, vector<int> arr1)
{
	int arrSize1 = arr1.size();
	// 갯수가 충분하지 않을 경우 추가하기
	if (arrSize1 < target)
	{
		vector<int> temp = arr1;
		if (num >= N)
			return;
		arr1.push_back(num);
		f_recur(target, num + 1, arr1);
		f_recur(target, num + 1, temp);
	}
	else if (arrSize1 == target)
	{
		vector<bool> check(N);
		for (int i = 0; i < arrSize1; i++)
			check[arr1[i]] = true;

		vector<int> arr2;
		for (int i = 0; i < N; i++)
			if (!check[i])
				arr2.push_back(i);

		// arr1 and arr2의 각각의 합
		int summ1 = 0;
		for (int i = 0; i < arrSize1; i++)
			for (int j = 0; j < arrSize1; j++)
				summ1 += arr[arr1[i]][arr1[j]];

		int summ2 = 0;
		int arrSize2 = arr2.size();
		for (int i = 0; i < arrSize2; i++)
			for (int j = 0; j < arrSize2; j++)
				summ2 += arr[arr2[i]][arr2[j]];

		// 갱신
		if (abs(summ1 - summ2) < minn)
			minn = abs(summ1 - summ2);
		return;
	}
	else
	{
		return;
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < N; j++)
		{
			temp.push_back(0);
			cin >> temp[j];
		}
		arr.push_back(temp);
		temp.clear();
	}
	vector<int> temp;
	f_recur(N / 2, 0, temp);

	std::cout << minn << std::endl;

	return 0;
}