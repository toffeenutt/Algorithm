#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N, K;
	std::cin >> N >> K;
	int cache[3000];
	cache[0] = 0;
	for (int i = 1; i < N; ++i)
	{
		cache[i] = 0;
		int ii = i - 1;
		for (int j = 0; j < ii; ++j)
		{
			cache[i] += 2 + (cache[j] << 1);
		}
	}
	int ans = 0;
	int NN = N - 2;
	for (int i = 0; i < NN; ++i) ans += cache[i];
	ans += (cache[N - (--K)] << 1);
	while (--K)
	{
		ans += cache[K]
	}
	std::cout << ans;
}