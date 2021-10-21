#include <iostream>
#include <memory.h>
int ground[100][100];
bool cache[100][100];	
int n;

bool solve(int r = 0, int c = 0)
{
	if (r == n - 1 && c == n - 1) return true;	//마지막 칸에 도달하면 성공 /마지막칸에 도달하면 재귀적으로 호출한 함수가 모두 true를 리턴함.

	int jump = ground[r][c];
	if (c + jump < n && !cache[r][c + jump] && solve(r, c + jump)) return true;
	//오른쪽으로 jump칸 가는 경우, 범위를 벗어나지 않고 캐시에 false가 있으면(경로가 없다고 확정되지 않은경우) 재귀호출. 그 경로에서 성공하면 즉시 true 리턴.
	if (r + jump < n && !cache[r + jump][c] && solve(r + jump, c)) return true;
	//오른쪽에서 실패시 똑같은 방법으로 아래로 감.
	cache[r][c] = true;	//둘다 실패시 메모이제이션(해당 칸은 경로가 없음이 확정됨)
	return false;
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
			for (int j = 0; j < n; ++j) std::cin >> ground[i][j];
			memset(cache[i], 0, n);
		}

		if (solve()) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
}