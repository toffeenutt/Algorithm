#include <iostream>
#include <iomanip>
int n, d, p;
bool way[50][50];
int numWay[50];
double probability[100][50];	//[d][n]일경우 d번째 날 n 마을에 있을 확률
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	std::cout << std::fixed << std::setprecision(8);
	while (C--)
	{
		std::cin >> n >> d >> p;
		for (int i = 0; i < n; ++i)
		{
			numWay[i] = 0;
			for (int j = 0; j < n; ++j)
			{
				std::cin >> way[i][j];	//i-j마을사이의 경로 유무 입력
				if (way[i][j]) ++numWay[i];	//i마을에서 다른마을로 가는 경로의 수 카운트(=다른마을에서 i마을로 가는 경로의 수)
			}
		}
		//
		for (int i = 0; i < n; ++i)	//첫째날 각 마을에 있을 확률 계산
		{
			if (way[p][i]) probability[0][i] = (double)1 / numWay[p];	//i마을로 가는 길이 있는경우
			else probability[0][i] = 0.0;	//없는경우
		}
		for (int i = 1; i < d; ++i) for (int j = 0; j < n; ++j)	//i번째 날 j마을에 있을 확률 계산
		{
			probability[i][j] = 0.0;
			for (int k = 0; k < n; ++k)	//j마을로 가는 경로가 있는 모든 k마을에 대해, 전날 k마을에있었을 확률 * k마을에서 j마을로 갈 확률 의 합
			{
				if (way[j][k]) probability[i][j] += probability[i - 1][k] / numWay[k];
			}
		}
		//
		int t, q;
		std::cin >> t;
		for (int i = 0; i < t; ++i)
		{
			std::cin >> q;
			std::cout << probability[d - 1][q] << ' ';
		}
		std::cout << '\n';
	}
}