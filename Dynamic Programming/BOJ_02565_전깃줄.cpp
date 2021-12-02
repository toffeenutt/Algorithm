#include <iostream>
#include <algorithm>
int n, pole[501], cache[501];	
int solve(int idx = 0)
{
	if (cache[idx] != -1) return cache[idx];
	int ret = 0;
	for (int i = idx + 1; i <= 500; ++i) if (pole[idx] < pole[i]) ret = std::max(ret, solve(i) + 1);
	return cache[idx] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{//왼쪽전봇대에서의 위치를 tmp, 오른쪽에 연결된 위치를 pole[tmp]라고 하면 왼쪽 전봇대의 위치 순서대로 오른쪽 전봇대의 위치가 자동으로 정렬된다.
		int tmp;
		std::cin >> tmp;
		std::cin >> pole[tmp];
		cache[tmp] = -1;
	}
	cache[0] = -1;
	std::cout << n - solve();
	//교차하지 않는 최대 전깃줄의 수를 구할 때
	//왼쪽 전봇대의 위치가 증가할 때마다 그에 연결된 오른쪽 전봇대의 위치가 증가해야 교차하지 않는 것이므로
	//정렬된 오른쪽 전봇대의 위치 수열의 가장 긴 증가하는 부분수열의 길이를 구하면 된다.
	//없애야 하는 전깃줄의 최소 개수는
	//전깃줄의 개수 - 교차하지 않는 최대 전깃줄의 개수이다.
}