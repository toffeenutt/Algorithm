#include <iostream>
#include <algorithm>
int n, quantity[10000], cache[10000][3];
int solve(int idx, int k)	//k = idx번부터 연속으로 마실 수 있는 포도주의 수
{
	if (idx == n) return 0;
	if (cache[idx][k] != -1) return cache[idx][k];
	//k = 0이면 idx번 포도주는 마시지 않고, 그렇지 않으면 마시는 경우와 마시지 않는 경우 중 큰 경우 선택
	return cache[idx][k] = std::max((k ? quantity[idx] + solve(idx + 1, k - 1) : 0), solve(idx + 1, 2));
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < 3; ++j) cache[i][j] = -1;
	for (int i = 0; i < n; ++i) std::cin >> quantity[i];
	std::cout << solve(0, 2);
}