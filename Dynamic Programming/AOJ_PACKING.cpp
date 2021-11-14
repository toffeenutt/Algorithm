#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
int n, w;
std::string name[100];
int volume[100], necessary[100];
int cache[101][1001];

int solve(int idx = 0, int vol = 0)	//기존에 고른 물건의 부피의 합이 vol이고 남은 idx~n-1번의 물건중에 골랐을 때 최대의 절박도를 리턴
{
	if (idx == n) return 0;
	if (cache[idx][vol]) return cache[idx][vol];

	int ret = solve(idx + 1, vol);	//idx를 안고르는 경우
	if (vol + volume[idx] <= w)	ret = std::max(ret, necessary[idx] + solve(idx + 1, vol + volume[idx]));	//idx를 고르는 경우
	return cache[idx][vol] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		memset(cache, 0, 101 * 1001 * sizeof(int));
		std::cin >> n >> w;
		for (int i = 0; i < n; ++i) std::cin >> name[i] >> volume[i] >> necessary[i];
		std::cout << solve() << ' ';
		//어떤 조합이 최대절박도인지 추적하기
		int idx = 0, vol = 0, cnt = 0;
		std::vector<std::string*> picked;
		while (idx != n)
		{
			if (cache[idx][vol] == cache[idx + 1][vol]) ++idx;	//둘이 같으면 idx는 안고른 것이다.
			else
			{//idx를 고른 경우
				picked.push_back(&name[idx]);
				vol += volume[idx++];
				++cnt;
			}
		}
		std::cout << cnt << '\n';
		for (int i = 0; i < picked.size(); ++i) std::cout << *picked[i] << '\n';
	}
}