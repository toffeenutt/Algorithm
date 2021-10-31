#include <iostream>
#include <algorithm>
#include <cmath>
int arr[100];
int N, S;
int cache[100][10];
int sum[100], sqsum[100]; //각각 0~i까지의 원소의 합, 원소의 제곱의 합

//n개의 원소를 s개의 묶음으로 나눈 상태에서 나머지 N-n개의 원소를 S-s개의 묶음으로 나누는 방법 중 오차제곱의 합이 최소인 경우를 찾는 함수
int solve(int n = 0, int s = 0)
{
	if (s == S) return 0;	//모든 원소가 양자화 된 경우
	if (cache[n][s] != -1) return cache[n][s];

	int ret = 987654321;

	//이번 묶음이 i개의 원소를 차지하는 경우(단, 마지막 묶음일 경우 남은 모든 원소를 차지하는 경우인 i = N - n 만을 실행)
	//N - n - (S - 1 - s) 는 이번 묶음에서 차지할 수 있는 최대 개수이다.(N - n = 남은 원소 수, S - 1 - s = 나머지 묶음들에서 필요한 최소 원소 수)
	for (int i = (s != S - 1 ? 1 : N - n); i <= N - n - (S - 1 - s); ++i)
	{
		int sumi = sum[n + i - 1] - (n == 0 ? 0 : sum[n - 1]);	//arr[n]~arr[n + i - 1]의 합(i개의 합)
		int q = (int)((double)sumi / i + 0.5);	//평균의 반올림

		//오차제곱의 합 = (arr[] - q)^2 을 전개하면 아래식이 된다.
		int tmp = sqsum[n + i - 1] - (n == 0 ? 0 : sqsum[n - 1]) - 2 * q * sumi + q * q * i;

		ret = std::min(ret, tmp + solve(n + i, s + 1));
	}
	return cache[n][s] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		std::cin >> N >> S;
		for (int i = 0; i < N; ++i)
		{
			std::cin >> arr[i];
			for (int j = 0; j < S; ++j) cache[i][j] = -1;
		}

		if (S >= N) std::cout << "0\n";	//S >= N인 경우 수열의 원소 그 자체를 양자화 된 값으로 볼 수 있으므로 오차제곱의 합은 0이다.
		else
		{
			//원소의 순서는 상관이 없고, 정렬했을 때 인접한 원소끼리 같은 숫자로 양자화 할 경우 오차 제곱의 합이 작아진다.
			//따라서 S개의 묶음으로 나누고 각 묶음이 몇 개의 원소를 차지하는지에 대해 완전탐색 하면 된다.
			std::sort(arr, arr + N);

			//구간의 합을 상수시간에 구하기 위해 사전에 배열에 계산해놓는다.
			sum[0] = arr[0];
			sqsum[0] = std::pow(arr[0], 2);
			for (int i = 1; i < N; ++i)
			{
				sum[i] = sum[i - 1] + arr[i];
				sqsum[i] = sqsum[i - 1] + std::pow(arr[i], 2);
			}

			std::cout << solve() << '\n';
		}
	}
}