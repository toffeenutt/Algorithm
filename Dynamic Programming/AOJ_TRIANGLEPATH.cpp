#include <iostream>
#include <algorithm>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int t[100][100];

	int C;
	std::cin >> C;
	while (C--)
	{
		int n;
		std::cin >> n;
		for (int i = 0; i < n; ++i) for (int j = 0; j <= i; ++j) std::cin >> t[i][j];
		/*
		어떤 경로로 t[i][j]에 내려왔는지에 관계 없이
		t[i][j]에서 내려가는 최대 경로는 항상 같으므로
		아래부터 차례대로 t[i][j]에서의 최대값을 구하면
		재귀호출을 하지 않고도 문제를 풀 수 있다.
		*/
		for (int i = n - 2; i >= 0; --i) for (int j = 0; j <= i; ++j)
		{
			t[i][j] += std::max(t[i + 1][j], t[i + 1][j + 1]);
		}

		std::cout << t[0][0] << '\n';
	}
}