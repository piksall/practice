// 백준 15649
#include<iostream>

int M, N;
int arr[9];
bool check[9] = { 0, };

// num번째 인자
void f_recur(int num)
{
	if (num == M + 1)
	{
		for (int i = 1; i <= M; i++)
			std::cout << arr[i] << " ";
		// 주의: "std::endl"의 경우 버퍼를 flush 하기 때문에
		// 실제로 출력 스트림이 반드시 완전히 넘어가게끔 하는 과정 필요
		std::cout << "\n";
		return;
	}
	else if (num > M + 1)
		return;
	else
	{
		for (int i = 1; i <= N; i++)
		{
			// in-out을 반복
			if (check[i] == false)
			{
				check[i] = true;
				arr[num] = i;
				f_recur(num + 1);
				check[i] = false;
			}
		}
	}
	return;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> N >> M;
	f_recur(1);
	return 0;
}
