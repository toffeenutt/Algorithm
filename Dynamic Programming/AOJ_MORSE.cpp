#include <iostream>
#include <algorithm>
#include <string>
int bino[200][100];	//bino[n + m][n] = 이항계수. 장점n개, 단점m개를 나열하는 경우의 수
std::string solve(int n, int m, int k)
{
	if (n == 0) return std::string(m, 'o');	//n==0이면 나머지는 m개의 단점으로 채운다.
	//이번칸에 장점을 선택할 때의 경우의수 bino[n + m - 1][n - 1] 이 k보다 크거나 같으면 장점을 선택
	if (bino[n + m - 1][n - 1] >= k) return "-" + solve(n - 1, m, k);
	//그렇지 않으면 장점을 선택하는 경우의 수 bino[n + m - 1][n - 1]만큼을 건너 뛸 수 있으므로 단점을 선택
	else return "o" + solve(n, m - 1, k - bino[n + m - 1][n - 1]);
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	for (int i = 0; i < 200; ++i)	//이항계수 먼저 계산
	{
		for (int j = 0; j <= i && j < 100; ++j)
		{
			if (j == 0 || j == i) bino[i][j] = 1;
			else bino[i][j] = std::min(1000000000, bino[i - 1][j - 1] + bino[i - 1][j]);
		}	//k의 최댓값이 10억이므로 10억을 넘어가는 값은 10억으로 저장(오버플로우 방지)
	}

	int C;
	std::cin >> C;
	while (C--)
	{
		int n, m, k;
		std::cin >> n >> m >> k;
		std::cout << solve(n, m, k) << '\n';
	}
}