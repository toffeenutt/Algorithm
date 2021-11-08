#include <iostream>
#include <algorithm>
int N;
int stairs[300];
int cache[300][2];
int solve(int idx = 0, bool prev_jmp = true)	//prev_jmp = true이면 idx에 올 때 2칸 점프한것, false이면 1칸 점프한것
{
	if (idx == N - 1) return stairs[idx];	//마지막 칸
	if (idx == N) return -987654321;	//마지막 칸을 넘은경우 경우의 수에 포함되지 않으므로 -987654321을 리턴(이 경우 최댓값을 찾을 때 알아서 걸러짐)
	if (cache[idx][prev_jmp]) return cache[idx][prev_jmp];
	int ret = -987654321;
	if (prev_jmp) ret = std::max(ret, solve(idx + 1, false));	//1칸 점프가 가능한 경우(이전에 2칸점프한 경우)
	ret = std::max(ret, solve(idx + 2, true));	//2칸 점프(2칸 점프는 이전의 점프랑 관계없이 무조건 수행)
	//idx 칸에서 이전점프가 prev_jmp였을 때(1칸or2칸) 이후 구간의 최댓값을 캐시에 저장 후 리턴
	return cache[idx][prev_jmp] = stairs[idx] + ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N;
	for (int i = 0; i < N; ++i) std::cin >> stairs[i];
	std::cout << std::max(solve(), solve(1));    //시작점에서 한칸(idx = 0), 두칸 점프(idx = 1)하는 경우에 대해 호출
}