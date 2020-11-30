//출처: 백준
//문제: 6603번 로또
//내용: Recursive function, Back tracking

#include <iostream>		// input&output
#include <vector>		// vector
#include <algorithm>	// sorting

#define LOTTO 6

std::vector<int> arr;
int k;

void f_recur(int num, std::vector<int> arr_)
{
	// if vector array has 6 numbers
	int arrSize = arr_.size();
	if (arrSize == LOTTO)
	{
		for (int i = 0; i < arrSize; i++)
		{
			std::cout << arr_[i];
			if (i != arrSize - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	// 6 < num
	else if (arrSize > LOTTO)
		return;
	// 6 > num
	else
	{
		if (num >= arrSize())
			return;
		// make new array with current number(int num)
		std::vector<int> temp = arr_;
		arr_.push_back(arr[num]);
		f_recur(num + 1, arr_);

		// make new array without current number(int num)
		f_recur(num + 1, temp);
	}
	return;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	int k;
	while (1)
	{
		std::cin >> k;
		if (k == 0)
			return 0;

		// candidate numbers
		for (int i = 0; i < k; i++)
		{
			arr.push_back(0);
			std::cin >> arr[i];
		}
		// descending
		sort(arr.begin(), arr.end());
		std::vector<int> temp;
		// zero-based recursive function
		f_recur(0, temp);
		std::cout << std::endl;
		arr.clear();
	}
	return 0;
}