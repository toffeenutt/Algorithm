#include <iostream>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t[100][100];
	int cases[100][100];

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
		아래부터 차례대로 올라가면서 t[i][j]에서의 최대값을 구하면
		재귀호출을 하지 않고도 최대값을 구할 수 있다.

		cases는 경로의 수를 저장할 배열이다.
		cases[i][j] 는 해당 칸에서 최대경로로 내려갈 수 있는 방법의 수이다.
		맨 아래칸은 모두 자신 그 자체가 최대경로이므로 방법의 수는 1이다.
		윗칸에서의 방법의 수는 아래, 아래오른쪽에서 둘 중 최대경로인 쪽에서의 방법의 수와 같다.
		단, 아래칸, 아래오른쪽칸이 둘다 최대경로라면 아래, 아래오른쪽에서의 방법의 수 의 합이다.
		*/
		for (int i = 0; i < n; ++i) cases[n - 1][i] = 1;
		for (int i = n - 2; i >= 0; --i) for (int j = 0; j <= i; ++j)
		{
			if (t[i + 1][j] > t[i + 1][j + 1])
			{
				t[i][j] += t[i + 1][j];
				cases[i][j] = cases[i + 1][j];
			}
			else if (t[i + 1][j] < t[i + 1][j + 1])
			{
				t[i][j] += t[i + 1][j + 1];
				cases[i][j] = cases[i + 1][j + 1];
			}
			else
			{
				t[i][j] += t[i + 1][j];
				cases[i][j] = cases[i + 1][j] + cases[i + 1][j + 1];
			}			
		}

		std::cout << cases[0][0] << '\n';
	}
}