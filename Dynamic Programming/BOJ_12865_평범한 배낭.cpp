#include <iostream>
#include <algorithm>
int N, K, weight[100], value[100], cache[101][100001];
int solve(int idx = 0, int w = 0)	//재귀함수 풀이법
{
	if (idx == N) return 0;
	if (cache[idx][w]) return cache[idx][w];
	int ret = solve(idx + 1, w);
	if (w + weight[idx] <= K) ret = std::max(ret, value[idx] + solve(idx + 1, w + weight[idx]));
	return cache[idx][w] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> K;
	for (int i = 0; i < N; ++i) std::cin >> weight[i] >> value[i];
	for (int i = N; i > 0; --i)	//반복문 풀이법
	{
		for (int j = 0; j <= K; ++j)
		{
			if (j - weight[i - 1] >= 0) cache[i - 1][j - weight[i - 1]] = std::max(cache[i - 1][j - weight[i - 1]], value[i - 1] + cache[i][j]);
			cache[i - 1][j] = std::max(cache[i - 1][j], cache[i][j]);
		}
	}
	//std::cout << solve();
	std::cout << cache[0][0];
}