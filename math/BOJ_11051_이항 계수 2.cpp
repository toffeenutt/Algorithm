#include <iostream>
#include <cmath>
int main()
{//이문제는 이항계수의 점화식을 이용하는걸 의도한 문제이지만, 나는 다르게 접근하였다.
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	//이항계수의 공식인 N!/((N-K)!*K!)에서 K!부분은 사전에 약분 가능하므로 약분한 것으로 처리하고,
	//남은 부분은 분자, 분모를 각각 소인수분해를 해서 약분하면 분모는 1이 되므로
	//남은 분자부분을 10007로 나눈 나머지를 구하면 된다.

	int N, K;
	std::cin >> N >> K;
	if (K <= N / 2) K = N - K;	//nCk = nCn-k 이므로 반복문의 반복횟수가 적은쪽을 선택
	int numerator[1000] = { 0 };	//분자의 소인수분해 (i^numerator[i]의 형태)
	int denominator[1000] = { 0 };	//분모의 소인수분해
	for (int i = K + 1, j = 1; i <= N; ++i, ++j)
	{
		int q = i;	//분자의 소인수분해
		while (true)
		{
			if (q % 2 == 0)
			{
				++numerator[2];
				q /= 2;
			}
			else break;
		}
		int z = 3;
		while (q != 1)
		{
			if (z > sqrt(q))
			{
				++numerator[q];
				break;
			}

			if (q % z == 0)
			{
				++numerator[z];
				q /= z;
			}
			else z += 2;
		}
		//
		q = j;	//분모의 소인수분해
		while (true)
		{
			if (q % 2 == 0)
			{
				++denominator[2];
				q /= 2;
			}
			else break;
		}
		z = 3;
		while (q != 1)
		{
			if (z > sqrt(q))
			{
				++denominator[q];
				break;
			}

			if (q % z == 0)
			{
				++denominator[z];
				q /= z;
			}
			else z += 2;
		}
	}

	N = 1;
	for (int i = 0; i < 1000; ++i)
	{
		numerator[i] -= denominator[i];	//약분
		N *= pow(i, numerator[i]);
		N %= 10007;
	}
	std::cout << N;
}