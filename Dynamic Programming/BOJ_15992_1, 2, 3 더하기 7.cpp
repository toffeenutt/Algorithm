#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int cache[1001][1001]; //cache[n][m] : n과 m이 주어졌을 때 1, 2, 3 총 m개 의 합으로 나타내는 방법의 수

	cache[0][0] = cache[1][1] = cache[2][1] = cache[2][2] = cache[3][1] = cache[3][3] = 1;
	cache[3][2] = 2;
	for (int i = 4; i <= 1000; ++i) cache[i][1] = 0;
	for (int i = 1; i <= 1000; ++i) cache[i][0] = 0;
	for (int j = 1; j <= 1000; ++j) cache[0][j] = 0;
	for (int j = 2; j <= 1000; ++j) cache[1][j] = 0;
	for (int j = 3; j <= 1000; ++j) cache[2][j] = 0;
	for (int j = 4; j <= 1000; ++j) cache[3][j] = 0;

	for (int i = 4; i <= 1000; ++i)
	{
		for (int j = 2; j <= 1000; ++j) cache[i][j] = ((long long)cache[i - 1][j - 1] + cache[i - 2][j - 1] + cache[i - 3][j - 1]) % 1000000009;
	}

	int T;
	std::cin >> T;

	while (T--)
	{
		int n, m;
		std::cin >> n >> m;
		std::cout << cache[n][m] << '\n';
	}
}