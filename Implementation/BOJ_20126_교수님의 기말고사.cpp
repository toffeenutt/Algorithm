#include <iostream>
#include <utility>
#include <algorithm>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M, S;
	std::cin >> N >> M >> S;
	std::pair<int, int> time[100000]; 
	for (int i = 0; i < N; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		time[i].first = a;
		time[i].second = a + b;		
	}
	sort(time, time + N);
	if (M <= time[0].first) std::cout << 0;
	else
	{
		int t = time[0].second;
		int i = 1;
		while (i != N && t + M > time[i].first)
		{
			t = time[i].second;
			++i;
		}
		if (i == N && t + M > S) std::cout << -1;
		else std::cout << t;
	}
}