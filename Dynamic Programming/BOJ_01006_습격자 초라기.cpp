#include <iostream>
#include <algorithm>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{
		int N, W;
		std::cin >> N >> W;
		int A[10000];
		int B[10000];
		for (int i = 0; i < N; ++i) std::cin >> A[i];
		for (int i = 0; i < N; ++i) std::cin >> B[i];
		
		if (N == 1) std::cout << (A[0] + B[0] <= W ? 1 : 2) << '\n';
		else if (N == 2)
			std::cout << std::min((A[0] + B[0] <= W ? 1 : 2) + (A[1] + B[1] <= W ? 1 : 2), (A[0] + A[1] <= W ? 1 : 2) + (B[0] + B[1] <= W ? 1 : 2))<< '\n';

		else
		{
			int dp1[10000], dp2[10000], dp3[10000];	//�Ѵ�����, ���ʸ� ���� A[i]B[i-1], �ٱ��ʸ� ���� A[i-1]B[i]

			//case1 ȯ�� �迭�� �� ������ �� �� ���� �ѼҴ밡 ���ÿ� Ŀ������ �ʴ� ���
			dp1[0] = (A[0] + B[0] <= W ? 1 : 2);
			dp1[1] = std::min(dp1[0] + (A[1] + B[1] <= W ? 1 : 2), (A[0] + A[1] <= W ? 1 : 2) + (B[0] + B[1] <= W ? 1 : 2));
			dp2[1] = (A[0] + B[0] <= W || A[0] + A[1] <= W ? 2 : 3);
			dp3[1] = (A[0] + B[0] <= W || B[0] + B[1] <= W ? 2 : 3);
			for (int i = 2; i < N; ++i)
			{
				dp2[i] = std::min(dp3[i - 1] + (A[i - 1] + A[i] <= W ? 1 : 2), dp1[i - 1] + 1);
				dp3[i] = std::min(dp2[i - 1] + (B[i - 1] + B[i] <= W ? 1 : 2), dp1[i - 1] + 1);
				dp1[i] = std::min(dp1[i - 1] + (A[i] + B[i] <= W ? 1 : 2),
					std::min(std::min(dp2[i], dp3[i]) + 1, dp1[i - 2] + (A[i - 1] + A[i] <= W ? 1 : 2) + (B[i - 1] + B[i] <= W ? 1 : 2)));
			}
			int ans = dp1[N - 1];

			//case2 ȯ�� �迭�� �� ������ �� ���ʸ�(A) �� �Ҵ밡 ���ÿ� Ŀ���ϴ� ���
			if (A[0] + A[N - 1] <= W)
			{
				dp1[0] = 2;
				dp1[1] = (A[1] + B[1] <= W || B[0] + B[1] <= W ? 3 : 4);
				dp2[1] = 3;
				dp3[1] = (B[0] + B[1] <= W ? 2 : 3);
				for (int i = 2; i < N - 1; ++i)
				{
					dp2[i] = std::min(dp3[i - 1] + (A[i - 1] + A[i] <= W ? 1 : 2), dp1[i - 1] + 1);
					dp3[i] = std::min(dp2[i - 1] + (B[i - 1] + B[i] <= W ? 1 : 2), dp1[i - 1] + 1);
					dp1[i] = std::min(dp1[i - 1] + (A[i] + B[i] <= W ? 1 : 2),
						std::min(std::min(dp2[i], dp3[i]) + 1, dp1[i - 2] + (A[i - 1] + A[i] <= W ? 1 : 2) + (B[i - 1] + B[i] <= W ? 1 : 2)));
				}
				ans = std::min(ans, std::min(dp1[N - 2] + 1, dp2[N - 2] + (B[N - 2] + B[N - 1] <= W ? 1 : 2)));
			}

			//case3 ȯ�� �迭�� �� ������ �� �ٱ��ʸ�(B) �� �Ҵ밡 ���ÿ� Ŀ���ϴ� ���
			if (B[0] + B[N - 1] <= W)
			{
				dp1[0] = 2;
				dp1[1] = (A[1] + B[1] <= W || A[0] + A[1] <= W ? 3 : 4);
				dp2[1] = (A[0] + A[1] <= W ? 2 : 3);
				dp3[1] = 3;
				for (int i = 2; i < N - 1; ++i)
				{
					dp2[i] = std::min(dp3[i - 1] + (A[i - 1] + A[i] <= W ? 1 : 2), dp1[i - 1] + 1);
					dp3[i] = std::min(dp2[i - 1] + (B[i - 1] + B[i] <= W ? 1 : 2), dp1[i - 1] + 1);
					dp1[i] = std::min(dp1[i - 1] + (A[i] + B[i] <= W ? 1 : 2),
						std::min(std::min(dp2[i], dp3[i]) + 1, dp1[i - 2] + (A[i - 1] + A[i] <= W ? 1 : 2) + (B[i - 1] + B[i] <= W ? 1 : 2)));
				}
				ans = std::min(ans, std::min(dp1[N - 2] + 1, dp3[N - 2] + (A[N - 2] + A[N - 1] <= W ? 1 : 2)));
			}

			//case4 ȯ�� �迭�� �� �������� �Ѵ� �� �Ҵ밡 ���ÿ� Ŀ���ϴ� ���
			if (A[0] + A[N - 1] <= W && B[0] + B[N - 1] <= W)
			{
				dp1[0] = 2;
				dp1[1] = (A[1] + B[1] <= W ? 3 : 4);
				dp2[1] = 3;
				dp3[1] = 3;
				for (int i = 2; i < N - 1; ++i)
				{
					dp2[i] = std::min(dp3[i - 1] + (A[i - 1] + A[i] <= W ? 1 : 2), dp1[i - 1] + 1);
					dp3[i] = std::min(dp2[i - 1] + (B[i - 1] + B[i] <= W ? 1 : 2), dp1[i - 1] + 1);
					dp1[i] = std::min(dp1[i - 1] + (A[i] + B[i] <= W ? 1 : 2),
						std::min(std::min(dp2[i], dp3[i]) + 1, dp1[i - 2] + (A[i - 1] + A[i] <= W ? 1 : 2) + (B[i - 1] + B[i] <= W ? 1 : 2)));
				}
				ans = std::min(ans, dp1[N - 2]);
			}
			std::cout << ans << '\n';
		}
	}
}