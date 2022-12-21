#include <iostream>
#include <vector>
#include <queue>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M, R;
	std::cin >> N >> M >> R;
	std::vector<std::priority_queue<int, std::vector<int>, std::greater<int>>> edges(N);
	for (int i = 0; i < M; ++i)
	{
		int s, d;
		std::cin >> s >> d;
		edges[--s].push(--d);	
		edges[d].push(s);
	}
	std::queue<int> Q;
	std::vector<bool> visited(N, false);
	std::vector<int> order(N);
	Q.push(--R);
	visited[R] = true;
	order[R] = 1;
	int ord = 1;
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		while (!edges[v].empty())
		{
			if (!visited[edges[v].top()])
			{
				Q.push(edges[v].top());
				visited[edges[v].top()] = true;
				order[edges[v].top()] = ++ord;
			}
			edges[v].pop();
		}
	}
	for (int i = 0; i < N; ++i) std::cout << order[i] << '\n';
}