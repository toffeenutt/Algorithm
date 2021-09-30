#include <iostream>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N, M, K;
	std::cin >> N >> M;
	int** A = new int* [N];
	for (int i = 0; i < N; ++i)
	{
		A[i] = new int[M];
		for (int j = 0; j < M; ++j) std::cin >> A[i][j];
	}
	std::cin >> M >> K;
	int** B = new int* [M];
	for (int i = 0; i < M; ++i) 
	{
		B[i] = new int[K];
		for (int j = 0; j < K; ++j) std::cin >> B[i][j];
	}
	
	int** C = new int* [N];
	for (int i = 0; i < N; ++i) C[i] = new int[K];

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			C[i][j] = 0;
			for (int q = 0; q < M; ++q)
			{
				C[i][j] += A[i][q] * B[q][j];
			}
			std::cout << C[i][j] << ' ';
		}
		std::cout << '\n';
	}
}