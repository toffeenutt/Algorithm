#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;
	std::cin >> N >> M;
	int psum[301][301];
	for (int i = 0; i <= M; ++i) psum[0][i] = 0;
	for (int i = 1; i <= N; ++i)
	{
		psum[i][0] = 0;
		std::cin >> psum[i][1];
		for (int j = 2; j <= M; ++j)
		{
			std::cin >> psum[i][j];
			psum[i][j] += psum[i][j - 1];
		}
		for (int j = 1; j <= M; ++j) psum[i][j] += psum[i - 1][j];
	}
	int K;
	std::cin >> K;
	while (K--)
	{
		int i, j, x, y;
		std::cin >> i >> j >> x >> y;
		std::cout << psum[x][y] - psum[x][j - 1] - psum[i - 1][y] + psum[i - 1][j - 1] << '\n';
	}
}