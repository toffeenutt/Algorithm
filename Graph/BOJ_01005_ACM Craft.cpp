#include <iostream>
#include <queue>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{
		int N, K;
		std::cin >> N >> K;
		int D[1001];
		for (int i = 1; i <= N; ++i) std::cin >> D[i];
		std::queue<int> edges[1001];
		int incomming[1001] = { 0 };
		while (K--)
		{
			int s, d;
			std::cin >> s >> d;
			edges[s].push(d);
			++incomming[d];
		}
		int W;
		std::cin >> W;

		int time[1001] = { 0 };
		std::queue<int> Q;
		for (int i = 1; i <= N; ++i) if (incomming[i] == 0)
		{
			time[i] = D[i];
			Q.push(i);
		}
		
		while (incomming[W] != 0)
		{
			int v = Q.front();
			Q.pop();
			while (!edges[v].empty())
			{
				int v2 = edges[v].front();
				edges[v].pop();
				if (time[v2] < time[v] + D[v2]) time[v2] = time[v] + D[v2];
				if (--incomming[v2] == 0) Q.push(v2);
			}
		}
		std::cout << time[W] << '\n';
	}
}