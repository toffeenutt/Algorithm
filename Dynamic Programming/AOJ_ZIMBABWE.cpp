#include <iostream>
#include <string>
#include <algorithm>
std::string e, sorted;
int m, cache[20][1 << 15][2];
int solve(int idx = 0, int r = 0, int picked = 0, bool less = false)
{
	if (cache[r][picked][less] != -1) return cache[r][picked][less];
	if (idx == e.size())
	{
		if (r == 0 && less) return cache[r][picked][less] = 1;	//마지막에 나머지가 0이고 e보다 작다면 경우의수 1추가
		else return cache[r][picked][less] = 0;
	}
	int ret = 0;
	for (int i = 0; i < sorted.size(); ++i)
		//뽑은적 없는 숫자이고, (첫번째 숫자거나, 앞 숫자와 다르거나, 앞 숫자와 같지만 이미 뽑힌 숫자이면) 뽑는다.(중복되는 숫자가 있을 때 같은 경우를 여러번 세는걸 피함)
		if (!(picked & (1 << i)) && (i == 0 || sorted[i - 1] != sorted[i] || (picked & (1 << (i - 1)))))
		{
			//지금까지 뽑은 결과가 이미 e보다 작은 경우
			if (less || e[idx] > sorted[i]) ret = (ret + solve(idx + 1, (r * 10 + sorted[i] - '0') % m, picked | (1 << i), true)) % 1000000007;
			//지금까지는 e와 같은 경우(앞으로 어떻게 뽑느냐에 따라 e보다 클 수도 있음)
			else if (e[idx] == sorted[i]) ret = (ret + solve(idx + 1, (r * 10 + sorted[i] - '0') % m, picked | (1 << i), false)) % 1000000007;
			//앞에서 숫자를 어떤 순서로 뽑았는지와 관계 없이 나머지 r 이 같고 picked가 같고 less가 같으면 항상 같은 결과이다.
		}
	return cache[r][picked][less] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		std::cin >> e >> m;
		sorted = e;
		std::sort(sorted.begin(), sorted.end());
		for (int i = 0; i < m; ++i) for (int j = 0; j < (1 << e.size()); ++j) cache[i][j][0] = cache[i][j][1] = -1;
		std::cout << solve() << '\n';
	}
}