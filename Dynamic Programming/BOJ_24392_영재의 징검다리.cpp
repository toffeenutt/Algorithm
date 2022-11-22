#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M;
	std::cin >> N >> M;
	unsigned int glass[1000][1002];
	for (int i = 0; i < N; ++i) for (int j = 1; j <= M; ++j) std::cin >> glass[i][j];
	glass[0][0] = glass[0][M + 1] = 0;	//유리의 왼쪽 끝, 오른쪽 끝의 경우 비효율적인 if문 대신 가상의 칸을 만들어 0으로 한것.
	for (int i = 1; i < N; ++i)
	{
		glass[i][0] = glass[i][M + 1] = 0;
		for (int j = 1; j <= M; ++j)
		{
			if (glass[i][j])
			{
				glass[i][j] = (glass[i - 1][j - 1] + glass[i - 1][j] + glass[i - 1][j + 1]) % 1000000007;
			}
		}
	}
	unsigned int ans = 0;
	--N;
	for (int i = 1; i <= M; ++i) ans = (ans + glass[N][i]) % 1000000007;
	std::cout << ans;
}