#include <iostream>
int N;
int cache[1000001];
/*
지금까지 이어붙인 타일의 개수를 i개라 할 때 남은 N - i 개의 타일의 가능한 조합의 모든 경우의 수를 구하는 재귀함수를 구현했다.
i개의 타일을 붙였을 때 다음 타일을 이어붙이는 선택지는 1(한개), 00(두개) 두가지 이므로 
solve(i) = solve(i + 1) + solve(i + 2) 이고
i == N이면 N개의 타일이 이어졌으므로 한 가지 경우의 수가 완성되어 1을 리턴하게 하였다.
int solve(int i = 0)
{
	if (i == N) return 1;
	if (i > N) return 0;
	if (cache[i]) return cache[i];
	return cache[i] = (solve(i + 1) + solve(i + 2)) % 15746;
}
이 함수로 옳은 결과를 얻을 수 있었지만 i가 커지면 재귀호출이 너무 많아 스택 오버플로우가 발생하였다.
따라서 재귀호출 보다는 반복문으로 구현해야 한다.(스택 예약 크기를 늘려 해결 할 수도 있다.)
재귀 호출의 흐름에서 처음으로 리턴되는 순간부터 역순으로 보면
피보나치 수열과 같다는걸 알 수 있다.
solve(N - 1) == solve(N) == 1 이므로 solve(N - 2) = solve(N - 1) + solve(N) == 2 이므로 피보나치 수열로 변형 할 수 있다. 
*/
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N;

	cache[0] = cache[1] = 1;
	for (int i = 2; i <= N; ++i)
	{
		cache[i] = (cache[i - 2] + cache[i - 1]) % 15746;
	}
	std::cout << cache[N];
}