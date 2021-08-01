#include <iostream>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
	{
		int n, m;
		std::cin >> n >> m;
		
		int n1 = 0, n2 = 1; //n1 = F(0) % m, n2 = F(1) % m
		int tmp;
		int period = 0;

		if (m == 1) period = 1;
		else while (true)
		{	//각 피보나치 수의 나머지 수열을 R(k) 라 하면
			//R(k) = (F(k-1) + F(k-2)) % m 이다.
			//(F(k-1) + F(k-2)) % m = (F(k-1) % m + F(k-2) % m) % m 이고
			//F(k-1) % m = R(k-1) 이므로 나머지 수열로 계산해도 된다.

			//R(k) = (R(k-1) + R(k-2)) % m 이다. (k >= 2)
			//n1: R(k-2), n2: R(k-1)
			tmp = (n1 + n2) % m;
			n1 = n2;
			n2 = tmp;
			++period;
			if (n1 == 0 && n2 == 1) break;
		}
		std::cout << n << ' ' << period << '\n';
	}
}