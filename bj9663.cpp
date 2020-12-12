/// 대표적인 백트래킹의 문제 중 하나
/// 처음 생각한 포인트는
/// 1. 퀸은 가로, 세로, 대각선에서 하나씩만 존재할 수 있으므로 퀸의 위치는 열 또는 행마다 하나씩만 있다.
/// 2. 열을 기준으로 y 값을 하나씩 내리면서
/// 2.1 만약 arr[y][x]의 값이 "0"이라면 check하고 (x+1, 0)의 위치로 이동한다.
/// 2.2 만약 arr[y][x]의 값이 "0"이 아니라면 넘어간다.
/// 3. 이렇게 끝까지 도달한 경우 검사를 한다.

/// 이를 토대로 처음 짠 코드와 코드의 결과는 다음과 같다.
/// 1. 이때 함수 동작은 정상적으로 작동 하나, 효율성 측면에서 크게 좋지 않다.
/// 2. 결과적으로 N = 14인 경우 1265초나 소모했는데 이는 f_recur 함수에서 불필요한 연산이 있기 때문이다.
/// 3. arr[y][x]가 마크가 되지 않은 경우 -> 그냥 넘기면 되는데 그러지 않았음
/// 4. 또한 y = N - 1, x = N - 1 즉, 끝까지 반복을 수행했기 때문에 연산이 비효율적임

/*
#include<iostream>
#include<time.h>
// int arr: 1 <= size < 15를 만족하는 대상 array
// int N: N개
// int cases: 총 경우의 수
int arr[14][14] = { 0, };
int N;
int cases = 0;


/// f_checkon: (y,x) 좌표의 가로, 세로, 대각선 on
/// int x: input x 좌표
/// int y: input y 좌표
void f_checkon(int y, int x)
{
	// 가로
	for (unsigned int i = 0; i < N; i++)
			arr[y][i] += 1;
	// 세로
	for (unsigned int i = 0; i < N; i++)
			arr[i][x] += 1;
	// LT-RB 대각선 (좌상대각선)
	int minn, h, w;
	minn = y > x ? x : y;
	h = y - minn;
	w = x - minn;
	while (w < N && h < N)
	{
		arr[h][w] += 1;
		h++;
		w++;
	}

	// LB-RT 대각선(우상대각선)
	minn = N - 1 - y > x ? x : N - 1 - y;
	h = y + minn;
	w = x - minn;
	while (w < N && h >= 0)
	{
		arr[h][w] += 1;
		h--;
		w++;
	}
}

/// f_checkoff: (y,x) 좌표의 가로, 세로, 대각선 off
/// int x: input x 좌표
/// int y: input y 좌표
void f_checkoff(int y, int x)
{
	// 가로
	for (unsigned int i = 0; i < N; i++)
		arr[y][i] -= 1;
	// 세로
	for (unsigned int i = 0; i < N; i++)
		arr[i][x] -= 1;
	// LT-RB 대각선 (좌상대각선)
	int minn, h, w;
	minn = y > x ? x : y;
	h = y - minn;
	w = x - minn;
	while (w < N && h < N)
	{
		arr[h][w] -= 1;
		h++;
		w++;
	}

	// LB-RT 대각선(우상대각선)
	minn = N - 1 - y > x ? x : N - 1 - y;
	h = y + minn;
	w = x - minn;
	while (w < N && h >= 0)
	{
		arr[h][w] -= 1;
		h--;
		w++;
	}
}

/// f_checknum:
/// 최종적으로 체크해서 판 확인하고 퀸이 정상적으로 위치한 경우 cases += 1
int f_checknum()
{
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if (arr[i][j] == 5)
				temp++;
	}
	return temp;
}

/// f_recur: 탐색을 위한 재귀함수

/// int x: input x 좌표
/// int y: input y 좌표
void f_recur(int y, int x)
{

	// y, x가 마크되지 않은 경우
	if (arr[y][x] == 0)
	{
		// 현재 위치 및 가로,세로,대각선 마크
		arr[y][x]++;
		f_checkon(y, x);

		// 다음 위치는 기본적으로 (0, x+1)의 위치가 됨
		if (x < N - 1)
			f_recur(0, x + 1);

		else if (x == N - 1)
		{

			if (f_checknum() == N)
			{
				cases++;
			}
		}

		// 재귀가 끝나면 전역변수인 arr을 초기화
		arr[y][x]--;
		f_checkoff(y, x);
	}

	// y, x가 마크된 경우
	else
	{
		if (y == N - 1)
		{
			// y가 가장 아래까지 내려왔는데, 더 이상 갈 곳이 없으므로 (0, x+1)의 위치로 이동
			if (x < N - 1)
				f_recur(0, x + 1);

			// 제일 끝(우하단)에 도달 할 경우 결과 확인하고 return 하기
			else if (x == N - 1)
			{
				if (f_checknum() == N)
				{
					cases++;
				}
			}
		}
	}
	if (y < N - 1)
		f_recur(y + 1, x);
	return;
}

int main()
{
	std::cin >> N;
	f_recur(0, 0);
	std::cout << cases << std::endl;
	return 0;
}
*/

/*
// RELEASE Mode, VS 2015
N = 0 / cases = 0 / Delay = 0s
N = 1 / cases = 1 / Delay = 0s
N = 2 / cases = 0 / Delay = 0s
N = 3 / cases = 0 / Delay = 0s
N = 4 / cases = 2 / Delay = 0s
N = 5 / cases = 10 / Delay = 0s
N = 6 / cases = 4 / Delay = 0s
N = 7 / cases = 40 / Delay = 0.001s
N = 8 / cases = 92 / Delay = 0.003s
N = 9 / cases = 352 / Delay = 0.023s
N = 10 / cases = 724 / Delay = 0.118s
N = 11 / cases = 2680 / Delay = 1.081s
N = 12 / cases = 14200 / Delay = 10.919s
N = 13 / cases = 73712 / Delay = 114.916s
N = 14 / cases = 365596 / Delay = 1265s
*/

/// 이후 문제점을 수정하고 새로 작성한 코드는 다음과 같음
#include<iostream>
#include<time.h>
// int arr: 1 <= size < 15를 만족하는 대상 array
// int N: N개
// int cases: 총 경우의 수
int N;
int cases = 0;
int arr[15][15] = {0, };

/// f_checkon: (y,x) 좌표의 가로, 세로, 대각선 on
/// int x: input x 좌표
/// int y: input y 좌표
void f_checkon(int y, int x)
{
	arr[y][x]++;
	// 가로
	for (unsigned int i = 0; i < N; i++)
		arr[y][i] += 1;
	// 세로
	for (unsigned int i = 0; i < N; i++)
		arr[i][x] += 1;
	// LT-RB 대각선 (좌상대각선)
	int minn, h, w;
	minn = y > x ? x : y;
	h = y - minn;
	w = x - minn;
	while (w < N && h < N)
	{
		arr[h][w] += 1;
		h++;
		w++;
	}

	// LB-RT 대각선(우상대각선)
	minn = N - 1 - y > x ? x : N - 1 - y;
	h = y + minn;
	w = x - minn;
	while (w < N && h >= 0)
	{
		arr[h][w] += 1;
		h--;
		w++;
	}
}

/// f_checkoff: (y,x) 좌표의 가로, 세로, 대각선 off
/// int x: input x 좌표
/// int y: input y 좌표
void f_checkoff(int y, int x)
{
	arr[y][x]--;
	// 가로
	for (unsigned int i = 0; i < N; i++)
		arr[y][i] -= 1;
	// 세로
	for (unsigned int i = 0; i < N; i++)
		arr[i][x] -= 1;
	// LT-RB 대각선 (좌상대각선)
	int minn, h, w;
	minn = y > x ? x : y;
	h = y - minn;
	w = x - minn;
	while (w < N && h < N)
	{
		arr[h][w] -= 1;
		h++;
		w++;
	}

	// LB-RT 대각선(우상대각선)
	minn = N - 1 - y > x ? x : N - 1 - y;
	h = y + minn;
	w = x - minn;
	while (w < N && h >= 0)
	{
		arr[h][w] -= 1;
		h--;
		w++;
	}
}

/// f_recur: 탐색을 위한 재귀함수
/// int x: input x 좌표
void f_recur(int x)
{
	/// x = 퀸의 갯수이자 x(열)의 위치
	/// 어차피 다음 열로 넘어가려면 퀸을 무조건 하나 놔야하고, 0-N까지 모든 퀸의 위치를 고려해야하므로
	/// for문으로 모든 값을 탐색함
	for (int i = 0; i < N; i++)
	{
		/// 만일 arr[i][x]의 위치에 퀸을 놓을 수 있고, 이 값이 가장 끝(N-1)의 위치가 아니라면
		/// 퀸을 두고 x+1의 위치로 이동함
		if (!arr[i][x] && x < N - 1)
		{
			/// 퀸을 두면 체크하고 재귀 함수가 끝나면 체크 해제해야함
			f_checkon(i, x);	
			f_recur(x + 1);
			f_checkoff(i, x);
		}
		/// 만일 마지막 열(x = N -1)이라면 퀸의 갯수를 세어서 확인해보기 
		else if (!arr[i][x] && x == N - 1)
		{
			f_checkon(i, x);
			
			int summ = 0;
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					if (arr[k][j] == 5)
						summ++;
			if (summ == N)
				cases++;
			
			f_checkoff(i, x);
		}
	}
	return;
}

int main()
{
	/*
	for (int i = 0; i < 15; i++)
	{
		cases = 0;
		clock_t start = clock();
		N = i;
		f_recur(0);
		//std::cout << cases << std::endl;
		clock_t end = clock();
		std::cout << "N = " << i << " / cases = " << cases  << " / Delay = " << float(end - start)/ CLOCKS_PER_SEC << "s" << std::endl;
	}
	*/
	std::cin >> N;
	f_recur(0);
	std::cout << cases << std::endl;
}

/// 결과적으로 속도가 크게 감소했음
/*
// RELEASE Mode, VS 2015
N = 0 / cases = 0 / Delay = 0s
N = 1 / cases = 1 / Delay = 0s
N = 2 / cases = 0 / Delay = 0s
N = 3 / cases = 0 / Delay = 0s
N = 4 / cases = 2 / Delay = 0s
N = 5 / cases = 10 / Delay = 0s
N = 6 / cases = 4 / Delay = 0s
N = 7 / cases = 40 / Delay = 0s
N = 8 / cases = 92 / Delay = 0.001s
N = 9 / cases = 352 / Delay = 0.002s
N = 10 / cases = 724 / Delay = 0.008s
N = 11 / cases = 2680 / Delay = 0.026s
N = 12 / cases = 14200 / Delay = 0.061s
N = 13 / cases = 73712 / Delay = 0.337s
N = 14 / cases = 365596 / Delay = 2.062s
*/
