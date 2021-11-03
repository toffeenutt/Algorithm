#include <iostream>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	/*
	2*n 공간을 2*1 타일로 채우는 문제이지만
	타일을 윗줄에 가로로 배치하면 아랫줄도 반드시 가로로 배치해야 하기 때문에 위아래가 대칭이다.
	따라서 n칸을 1칸혹은 2칸짜리 타일로 채우는 문제와 같다.

	지금까지 채운 칸을 i라 할 때 남은 N - i 칸에서 가능한 조합의 모든 경우의 수를 구하는 재귀함수를 구현했다.
	i개의 칸을 채웠을 때 다음 칸을 채우는 선택지는 한개짜리, 두개짜리 두가지 이므로
	solve(i) = solve(i + 1) + solve(i + 2) 이고
	i == N이면 모든 칸이 채워졌으므로 한 가지 경우의 수가 완성되어 1을 리턴하게 하였다.
	int solve(int i = 0)
	{
		if (i == N) return 1;
		if (i > N) return 0;
		if (cache[i]) return cache[i];
		return cache[i] = (solve(i + 1) + solve(i + 2)) % 1000000007;
	}
	재귀 호출의 흐름에서 처음으로 리턴되는 순간부터 역순으로 보면
	피보나치 수열과 같다는걸 알 수 있다.
	solve(N - 1) == solve(N) == 1 이므로 solve(N - 2) = solve(N - 1) + solve(N) == 2 이므로 피보나치 수열로 변형 할 수 있다.
	*/

	int cache[101];
	cache[0] = cache[1] = 1;
	for (int i = 2; i <= 100; ++i) cache[i] = (cache[i - 2] + cache[i - 1]) % 1000000007;

	int C;
	std::cin >> C;
	while (C--)
	{
		int N;
		std::cin >> N;
		std::cout << cache[N] << '\n';
	}
}