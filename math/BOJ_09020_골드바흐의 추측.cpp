#include <iostream>
#include <cmath>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	//에라토스테네스의 체
	bool eratosthenes[10000 + 1] = { 0 };
	for (int i = 4; i <= 10000; i += 2) eratosthenes[i] = 1;
	for (int i = 3; i <= sqrt(10000); i += 2)
	{
		if (!eratosthenes[i])
		{
			for (int j = i * i; j <= 10000; j += i + i) eratosthenes[j] = 1;
		}
	}

	int T;
	std::cin >> T;
	while (T--)
	{
		int N;
		std::cin >> N;
		if (N == 4)	//4일경우만 따로 처리
		{
			std::cout << 2 << ' ' << 2 << '\n';
			continue;
		}
		int i = ((N / 2) % 2) ? (N / 2) : (N / 2 - 1);
		//두 소수의 차가 가장 작은 것을 출력해야 하므로 N / 2부터 시작(짝수일경우 1뺌)
		while (true)
		{
			if ((!eratosthenes[i]) && (!eratosthenes[N - i]))	//i와 N-i둘다 소수이면 출력
			{
				std::cout << i << ' ' << N - i << '\n';
				break;
			}
			i -= 2;	//짝수건너뛰기
		}
	}
}