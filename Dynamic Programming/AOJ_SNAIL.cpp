#include <iostream>
#include <iomanip>
int n, m;
double cache[1001][1001];

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	std::cout << std::fixed << std::setprecision(10);
	while (C--)
	{
		std::cin >> n >> m;
		if (n > 2 * m) std::cout << 0.0 << '\n';	//매일 비가와도 끝에 도달할 수 없는 경우
		else if (n <= m) std::cout << 1.0 << '\n';	//비가 오지 않아도 끝에 도달하는 경우
		else
		{	//cache[d][r] = d일동안 r일 비가 왔을 때, 남은 m-d일 동안 끝에 도달할 확률
			for (int i = 0; i < n - m; ++i) cache[m][i] = 0;	//총 m일 중 n-m일 미만으로 비가 온 경우 n미터에 도달하지 못함, 즉 확률 0
			for (int i = n - m; i <= m; ++i) cache[m][i] = 1;	//n-m일 이상 비가 온 경우 n미터에 도달함, 확률 1

			//i일중 j일 비가 왔을 때, 끝에 도달할 확률은 아래 식과 같다.
			for (int i = m - 1; i >= 0; --i) for (int j = 0; j <= i; ++j) cache[i][j] = 0.75 * cache[i + 1][j + 1] + 0.25 * cache[i + 1][j];
			// == 다음 날 비가 올 확률 0.75 * 그 경우 끝에 도달할 확률 + 다음 날 비가 안올 확률 0.25 * 그 경우 끝에 도달할 확률

			std::cout << cache[0][0] << '\n';
		}
	}
}