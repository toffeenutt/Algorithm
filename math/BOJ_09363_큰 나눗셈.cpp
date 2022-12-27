#include <iostream>
#include <vector>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	bool eratos[1000001] = { 0 };	//�����佺�׳׽��� ü
	for (int i = 4; i <= 1000000; i += 2) eratos[i] = 1;
	for (int i = 3; i <= 1000; i += 2) if (!eratos[i]) for (int j = i * i; j <= 1000000; j += i << 1) eratos[j] = 1;

	std::vector<int> prime;
	int nth_prime[1000000];	//nth_prime[i] = n; i�� n��° �Ҽ�
	int k = 0;
	for (int i = 2; i < 1000000; ++i)
		if (!eratos[i])
		{
			prime.push_back(i);
			nth_prime[i] = k++;
		}
	int psize = prime.size();

	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		int N, M;
		std::cin >> N >> M;
		std::vector<int> prime_factors_A(psize);	//���μ������� �����κ�
		std::vector<int> prime_factors_B(psize);
		for (int i = 0; i < N; ++i)
		{
			int A;
			std::cin >> A;
			int j = 0;
			while (A != 1) //A���μ�����
			{
				if (!eratos[A])
				{
					++prime_factors_A[nth_prime[A]];
					break;
				}
				if (A % prime[j] == 0)
				{
					++prime_factors_A[j];
					A /= prime[j];
				}
				else ++j;
			}
		}
		for (int i = 0; i < M; ++i)
		{
			int B;
			std::cin >> B;
			int j = 0;
			while (B != 1) //B���μ�����
			{
				if (!eratos[B])
				{
					++prime_factors_B[nth_prime[B]];
					break;
				}
				if (B % prime[j] == 0)
				{
					++prime_factors_B[j];
					B /= prime[j];
				}
				else ++j;
			}
		}

		for (int i = 0; i < psize; ++i) //���
		{
			if (prime_factors_A[i] == prime_factors_B[i]) prime_factors_A[i] = prime_factors_B[i] = 0;
			else if (prime_factors_A[i] > prime_factors_B[i])
			{
				prime_factors_A[i] -= prime_factors_B[i];
				prime_factors_B[i] = 0;
			}
			else
			{
				prime_factors_B[i] -= prime_factors_A[i];
				prime_factors_A[i] = 0;
			}
		}
		int X = 1, Y = 1;
		for (int i = 0; i < psize; ++i)
		{
			while (prime_factors_A[i]--) X *= prime[i];
			while (prime_factors_B[i]--) Y *= prime[i];
		}
		std::cout << "Case #" << t << ": " << X << " / " << Y << '\n';
	}
}