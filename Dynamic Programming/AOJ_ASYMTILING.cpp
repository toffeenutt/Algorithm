#include <iostream>
#define m 1000000007
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int cache[101];
	cache[0] = cache[1] = 1;
	for (int i = 2; i <= 100; ++i) cache[i] = (cache[i - 2] + cache[i - 1]) % m;
	//타일을 채우는 모든 경우의 수 - 대칭인 경우의 수 를 해주면 된다.
	//타일을 채우는 모든 경우의 수는 TILING2 문제와 같으므로 피보나치 수열로 구한다.
	//대칭인 경우의 수는
	//N이 홀수인 경우
	//가운데 칸에 세로로 타일을 배치 하고 N/2 칸에 타일을 배치하는 경우의 수와 같다.(왼쪽에 배치한걸 오른쪽에 반대로 배치하면 대칭이므로)

	//N이 짝수인 경우
	//반으로 나누어 N/2칸에 타일을 배치하는 경우의 수 + 가운데 두칸에 가로로 타일을 배치하고 N/2 - 1 칸에 타일을 배치하는 경우의 수 이다.
	int C;
	std::cin >> C;
	while (C--)
	{
		int N;
		std::cin >> N;
		std::cout << (N % 2 ? (m + cache[N] - cache[N / 2]) % m : (2 * m + (long long)cache[N] - cache[N / 2] - cache[N / 2 - 1]) % m) << '\n';
	}
}