#include <iostream>
#include <algorithm>
int n, seq[1001], cache[1001][2];
int solve(int idx = 0, bool k = true)	//k = true이면 증가, false이면 감소
{
	if (cache[idx][k] != -1) return cache[idx][k];
	int ret = 0;
	if (k) for (int i = idx + 1; i <= n; ++i)
	{//k = true이면 i까지 증가한 것이므로 계속 증가하는 경우와 i의 다음부터는 감소하는 경우 중 더 큰 값을 리턴
		if (seq[idx] < seq[i])	ret = std::max(ret, std::max(solve(i), solve(i, false)) + 1);
	}
	else for (int i = idx + 1; i <= n; ++i)
	{//k = false이면 앞으로는 계속 감소해야함(한번 감소하기 시작하면 끝까지 감소)
		if (seq[idx] > seq[i]) ret = std::max(ret, solve(i, false) + 1);
	}
	return cache[idx][k] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> seq[i];
		cache[i][0] = cache[i][1] = -1;
	}
	cache[0][0] = cache[0][1] = -1;
	std::cout << solve();
}