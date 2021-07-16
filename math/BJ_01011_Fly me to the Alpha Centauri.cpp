#include <iostream>
#include <cmath>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int T;
	std::cin >> T;
	while (T--)
	{
		int x, y;
		std::cin >> x >> y;
		x = y - x;
		//2 6 12 20 30 42... 규칙
		//등차수열의 합 : (첫항 + 마지막항) * 항의 개수 / 2 
		//((n + 2) * (n / 2)) / 2 = n(n+2)/4 = x
		//n^2 + 2n -4x = 0
		//짝수근의공식의 양수 부분 : -1 + sqrt(1 + 4 * x)		을 올림
		long long n = ceil(-1 + sqrt(1 + 4 * (long long)x));	//4를 곱할것이므로 int사용시 overflow 가능성
		if (n % 2) ++n;
		if (n * (n + 2) / 4 - x >= n / 2) --n;
		std::cout << n << '\n';
	}
}