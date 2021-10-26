#include <iostream>
#include <algorithm>
int n;
int progression[500];
int cache[500];

int solve(int idx)	//함수 호출 == 부분수열에 progression[idx] 를 추가하는것
{
	if (cache[idx]) return cache[idx];	//이미 캐시에 있으면 바로 리턴

	int count = 0;
	for (int j = idx + 1; j < n; ++j) if (progression[j] > progression[idx])
	{//순증가 수열을 찾아야 하므로 이전값(progression[idx]보다 큰 값만 부분수열에 포함하면 된다.)
		count = std::max(count, solve(j));	//그 중 가장 큰 값이 count이다
	}
	return cache[idx] = ++count;	//캐싱후 리턴
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int C;
	std::cin >> C;
	while (C--)
	{
		std::cin >> n;
		for (int i = 0; i < n; ++i)
		{
			std::cin >> progression[i];
			cache[i] = 0;
		}

		int max = 0;
		for (int i = 0; i < n; ++i)	//모든 원소를 부분수열의 첫 원소로 하여 호출
		{
			max = std::max(max, solve(i));
		}
		std::cout << max << '\n';	
	}
}