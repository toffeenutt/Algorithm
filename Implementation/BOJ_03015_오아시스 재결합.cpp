#include <iostream>
#include <stack>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N;
	std::cin >> N;
	long long pair_cnt = 0;
	std::stack<std::pair<int, int>> st;
	int height;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> height;
		while (!st.empty() && height > st.top().first)
		{
			pair_cnt += st.top().second;
			st.pop();
		}
		if (st.empty()) st.push(std::pair<int, int>(height, 1));
		else if (height < st.top().first)
		{
			++pair_cnt;
			st.push(std::pair<int, int>(height, 1));
		}
		else
		{
			if (st.size() == 1) pair_cnt += st.top().second;
			else pair_cnt += st.top().second + 1;
			++st.top().second;
		}
	}
	std::cout << pair_cnt;
}