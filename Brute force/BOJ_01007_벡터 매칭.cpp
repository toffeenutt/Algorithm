#include <iostream>
#include <algorithm>
#include <cmath>
#include <float.h>
#include <iomanip>
int N;
int x[20], y[20];
double ans;
void solve(int n, int k, int X, int Y)
{
	if (n == N / 2)
	{
		ans = std::min(ans, std::sqrt(std::pow(X, 2) + std::pow(Y, 2)));
		return;
	}
	for (int i = k; i < N; ++i)
	{
		solve(n + 1, i + 1, X - (x[i] << 1), Y - (y[i] << 1));
	}
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cout << std::setprecision(10) << std::fixed;
	int T;
	std::cin >> T;
	while (T--)
	{
		std::cin >> N;
		int Xsum = 0, Ysum = 0;
		for (int i = 0; i < N; ++i)
		{
			std::cin >> x[i] >> y[i];
			Xsum += x[i];
			Ysum += y[i];
		}
		ans = DBL_MAX;
		solve(0, 0, Xsum, Ysum);
		std::cout << ans << '\n';
	}
}