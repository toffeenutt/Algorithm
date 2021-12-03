#include <iostream>
#include <algorithm>
#include <iomanip>
#include <memory.h>
int N;
double dist[15][15], cache[15][1 << 15];
//city에서 출발하여 아직 방문하지 않은 도시를 모두 방문하는 최소 거리를 리턴하는 함수
double solve(int city, int visit)	//visit: 지금까지 방문했던 도시의 정보(2^방문한city 의 합)
{
	if (visit == (1 << N) - 1) return 0.0;	//모든 도시를 방문한 경우
	if (cache[city][visit]) return cache[city][visit];
	double ret = INFINITY;	//방문하지 않은 도시만 방문하고, 그중 최소거리를 찾는다.
	for (int i = 0; i < N; ++i) if (!(visit & (1 << i))) ret = std::min(ret, dist[city][i] + solve(i, visit + (1 << i)));
	return cache[city][visit] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	std::cout << std::fixed << std::setprecision(10);
	while (C--)
	{
		std::cin >> N;
		for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) std::cin >> dist[i][j];
		double result = INFINITY;
		for (int i = 0; i < N; ++i) result = std::min(result, solve(i, 1 << i));
		std::cout << result << '\n';
		memset(cache, 0, 15 * (1 << 15) * sizeof(double));
	}
}