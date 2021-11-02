#include <iostream>
#include <algorithm>
int N;
int cost[1000][3];	//cost[i][j] = i번째 집을 j색으로 칠하는 비용(j = 0 빨간색 1 초록색 2 파란색)
int cache[1000][3];	//cache[i][j] = i-1 번째 집이 j색 일 때 나머지 i~N-1집을 칠하는 최소 비용
int solve(int idx, int prev_color)
{
	if (idx == N) return 0;
	if (cache[idx][prev_color]) return cache[idx][prev_color];
	int ret = 987654321;
	for (int c = 0; c < 3; ++c)
	{//앞집과 같은 색은 피한다. 단 idx == 0이면 3가지 색깔을 모두 시도한다.
		if (c != prev_color || idx == 0) ret = std::min(ret, cost[idx][c] + solve(idx + 1, c));
	}
	return cache[idx][prev_color] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N;
	for (int i = 0; i < N; ++i) std::cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	std::cout << solve(0, 0);
}