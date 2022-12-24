#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N;
	std::cin >> N;
	int ans[10002];
	int k = N;
	ans[N + 1] = k;
	for (int i = N; i > 0; --i)
	{
		if (ans[i + 1] == k)
		{
			k = i;
			int pow2 = 1;
			while (k >= pow2) pow2 <<= 1;
			ans[i] = pow2 - k;
		}
		else ans[i] = ans[i + 1] + 1;
	}
	for (int i = 1; i <= N; ++i) std::cout << ans[i] << '\n';
}