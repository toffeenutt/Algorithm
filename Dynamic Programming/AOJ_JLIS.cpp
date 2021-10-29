#include <iostream>
#include <algorithm>
int nA, nB;
int progressionA[100];
int progressionB[100];
int cache[101][101];

//main에서 함수를 처음 호출할 때 별도의 처리를 하지 않기 위해서 -1, -1에서 시작하는 것으로 함
int solve(int idxA = -1, int idxB = -1)
{
	if (cache[idxA + 1][idxB + 1]) return cache[idxA + 1][idxB + 1];	//이미 캐시에 있으면 바로 리턴

	long long tmp = std::max((idxA != -1 ? progressionA[idxA] : -2147483649), (idxB != -1 ? progressionB[idxB] : -2147483649));
	//tmp = 직전에 뽑은 수
	int count = 0;
	for (int i = idxA + 1; i < nA; ++i) if (progressionA[i] > tmp) count = std::max(count, solve(i, idxB));
	for (int i = idxB + 1; i < nB; ++i) if (progressionB[i] > tmp) count = std::max(count, solve(idxA, i));

	return cache[idxA + 1][idxB + 1] = ++count;	//캐싱후 리턴
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		std::cin >> nA >> nB;
		for (int i = 0; i < nA; ++i) std::cin >> progressionA[i];
		for (int i = 0; i < nB; ++i) std::cin >> progressionB[i];
		for (int i = 0; i <= nA; ++i) for (int j = 0; j <= nB; ++j) cache[i][j] = 0;

		std::cout << solve() - 1 << '\n';	//아무것도 뽑지 않은 -1, -1인 상태도 세기 때문에 1을 빼줌
	}
}