#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	int count = 0;
	int i = 666;
	while (count != N)
	{
		int tmp = i;
		while (tmp > 99)	//두자리 수가 되기 전까지 10으로 나누면서 666이 있는지 확인
		{
			if (tmp % 1000 == 666)
			{
				++count;
				break;
			}

			tmp /= 10;
		}
		++i;
	}

	std::cout << --i;
}