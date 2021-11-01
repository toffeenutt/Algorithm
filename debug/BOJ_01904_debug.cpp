#include <iostream>
#include <exception>
int N;
int cache[1000001];
int solve(int i = 0)
{
	if (i == N) return 1;
	if (i > N) return 0;
	if (cache[i]) return cache[i];
	return cache[i] = (solve(i + 1) + solve(i + 2)) % 15746;
}
//i가 너무 커지면 스택 오버플로우가 발생한다.
//VS기준 프로젝트-속성-링커-시스템-스택예약크기 에서 스택예약크기를 적절하게 늘려주면 된다.
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N;

	std::cout << solve();
}