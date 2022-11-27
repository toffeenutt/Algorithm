#include <iostream>
#include <string.h>
int N;
int** solve(int** m, int K)
{
	if (K == 1) return m;

	int **matrix1, **matrix2;
	if (K % 2)
	{
		matrix1 = solve(m, K - 1);
		matrix2 = m;
	}
	else matrix1 = matrix2 = solve(m, K / 2);

	int** ans = new int* [N];
	ans[0] = new int[N * N];
	for (int i = 1; i < N; ++i) ans[i] = &ans[0][N * i];
	memset(ans[0], 0, sizeof(int) * N * N);

	for (int i = 0; i < N; ++i)
	{
		for (int k = 0; k < N; ++k)
		{
			for (int j = 0; j < N; ++j)	ans[i][j] = (ans[i][j] + (int)(((long long)matrix1[i][k] * matrix2[k][j]) % 1000000007)) % 1000000007;
		}
	}
	return ans;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int K;
	std::cin >> N >> K;

	int** matrix = new int* [N];
	matrix[0] = new int[N*N];
	for (int i = 1; i < N; ++i) matrix[i] = &matrix[0][N * i];
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) std::cin >> matrix[i][j];

	matrix = solve(matrix, K);
	int ans = 0;
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) ans = (ans + matrix[i][j]) % 1000000007;
	std::cout << ans;
}