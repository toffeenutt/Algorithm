#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N, M;
	std::cin >> N >> M;

	int* deck = new int[N];
	for (int i = 0; i < N; ++i) std::cin >> deck[i];

	int max_below_M = 0;
	for (int i = 0; i < N - 2; ++i)	//N개중 순서에 관계 없이 3개를 뽑는 조합의 모든 경우의 수
	{
		for (int j = i + 1; j < N - 1; ++j)
		{
			for (int k = j + 1; k < N; ++k)
			{
				int sum = deck[i] + deck[j] + deck[k];
				if (sum > max_below_M && sum <= M) max_below_M = sum;
			}
		}
	}
	std::cout << max_below_M;
}