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
	//N�� �ִ� 10^12������, �� ���� ���� N�� �ִ� M������ ���� �� �����Ƿ� N % M���� �޸������̼��� �� �ִ�.
	if (cache[r][round] != -1) return cache[r][round];
	else if (r == 0) return cache[r][round] = solve(N - q, M, round - 1);
	//�������� 0�� ��, N - q�� �ٸ� N�� N-q Ȥ�� N-q-1�� �����Ƿ� ������ �þ�� �ʴ´�.
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