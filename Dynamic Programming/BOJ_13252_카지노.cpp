#include <iostream>
double cache[50][51];	
double solve(long long N, int M, int round)
{
	if (round == 0)
	{
		if (N > 0) return 1;
		else return 0;
	}

	long long q = N / M;
	int r = N % M;
	//N은 최대 10^12이지만, 각 라운드 마다 N은 최대 M가지만 있을 수 있으므로 N % M으로 메모이제이션할 수 있다.
	if (cache[r][round] != -1) return cache[r][round];
	else if (r == 0) return cache[r][round] = solve(N - q, M, round - 1);
	//나머지가 0일 때, N - q가 다른 N의 N-q 혹은 N-q-1과 같으므로 개수가 늘어나지 않는다.
	else return cache[r][round] = (double)(M - r) / M * solve(N - q, M, round - 1) + (double)r / M * solve(N - q - 1, M, round - 1);

}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	long long N;
	int M, K;
	std::cin >> N >> M >> K;
	for (int i = 0; i < 50; ++i) for (int j = 0; j <= 50; ++j) cache[i][j] = -1;
	if (M == 1) std::cout << 0;
	else std::cout << solve(N, M, K);
}