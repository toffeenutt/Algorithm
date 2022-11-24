#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N, K;
	std::cin >> N >> K;
	int cache[3000];
	cache[0] = cache[1] = 0;
	for (int i = 2; i < N; ++i) cache[i] = (cache[i - 1] + (cache[i - 2] << 1) % 1000000007 + 2) % 1000000007;

	if (K == N) std::cout << cache[N - 1];
	else
	{
		int ans = 0;
		int NN = N - 2;
		for (int i = 0; i < NN; ++i) ans = (ans + 1 + cache[i]) % 1000000007;	//¿À¸¥ÂÊ

		//¿ÞÂÊ
		if (K == 1) ans = (ans + 1 + cache[NN]) % 1000000007;
		else if (K == 2) ans = (ans + 2 + (cache[N - 3] << 1) % 1000000007) % 1000000007;
		else
		{
			ans = (ans + 2 + (cache[N - 1 - K] << 1) % 1000000007) % 1000000007;
			for (int i = N - K; i < NN; ++i) ans = (ans + 1 + cache[i]) % 1000000007;
		}
		std::cout << ans;
	}
}