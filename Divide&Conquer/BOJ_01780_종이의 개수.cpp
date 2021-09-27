#include <iostream>
int N;
int matrix[2187][2187];
int s1 = 0, s2 = 0, s3 = 0;
int same(int r, int c, int N)
{
	for (int i = r; i < r + N; ++i) for (int j = c; j < c + N; ++j) if (matrix[i][j] != matrix[r][c]) return 2;
	return matrix[r][c];
}
void solve(int r, int c, int N)
{
	int s = same(r, c, N);
	if (s == -1) ++s1;
	else if (s == 0) ++s2;
	else if (s == 1) ++s3;
	else
	{
		solve(r, c, N / 3);
		solve(r, c + N / 3, N / 3);
		solve(r, c + N / 3 * 2, N / 3);

		solve(r + N / 3, c, N / 3);
		solve(r + N / 3, c + N / 3, N / 3);
		solve(r + N / 3, c + N / 3 * 2, N / 3);

		solve(r + N / 3 * 2, c, N / 3);
		solve(r + N / 3 * 2, c + N / 3, N / 3);
		solve(r + N / 3 * 2, c + N / 3 * 2, N / 3);
	}
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N;
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) std::cin >> matrix[i][j];
	solve(0, 0, N);
	std::cout << s1 << '\n' << s2 << '\n' << s3;
}