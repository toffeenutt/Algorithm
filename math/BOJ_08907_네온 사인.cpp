#include <iostream>
#include <algorithm>
#include <string.h>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin >> T;
	while (T--)
	{
		int N;
		std::cin >> N;
		int red_cnt[1000];
		memset(red_cnt, 0, sizeof(int) * N);
		for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j)
		{
			int tube;
			std::cin >> tube;
			red_cnt[i] += tube;
			red_cnt[j] += tube;
		}
		int two_colored = 0;	//두 선분의 색이 다른 각의 개수
		for (int i = 0; i < N; ++i) two_colored += red_cnt[i] * (N-1 - red_cnt[i]);

		std::cout << (N * (N - 1) * (N - 2) / 6) - (two_colored / 2) << '\n';	//전체 삼각형의 개수 - 단색이 아닌 삼각형의 개수
		//단색이 아닌 삼각형은 반드시 두 선분의 색이 다른 각을 2개 갖는다.
		//따라서 단색이 아닌 삼각형의 개수 = two_colored / 2
	}
}