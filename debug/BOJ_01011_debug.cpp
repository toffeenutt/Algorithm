#include <iostream>
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
		//x가 2^31에 가까울 때 문제 발생.
		//int i = 1, s = 0;
		long long i = 1, s = 0;
		while (s < x) s += i++ * 2;    //s 가 int일때 2^31 - 1보다 커지면 오버플로우 나서 무한루프.
		//long long 으로 해결.
		if (s - --i < x) std::cout << i * 2 << '\n';
		else std::cout << i * 2 - 1 << '\n';
	}
}