#include <iostream>
int N;
int x[50000], y[50000];

bool solve(int idx, char first, int line1, char second, int line2, char third, int line3)
{
	if (idx == N) return true;

	if (first == '0')
	{
		if (solve(idx + 1, 'x', x[idx], '0', -1, '0', -1)) return true;
		if (solve(idx + 1, 'y', y[idx], '0', -1, '0', -1)) return true;
		return false;
	}
	int* ptr;
	if (first == 'x') ptr = x;
	else ptr = y;

	if (line1 == ptr[idx]) return solve(idx + 1, first, line1, second, line2, third, line3); 
	else
	{
		if (second == '0')
		{
			if (solve(idx + 1, first, line1, 'x', x[idx], '0', -1)) return true;
			if (solve(idx + 1, first, line1, 'y', y[idx], '0', -1)) return true;
			return false;
		}

		if (second == 'x') ptr = x;
		else ptr = y;

		if (line2 == ptr[idx]) return solve(idx + 1, first, line1, second, line2, third, line3); 
		else
		{
			if (third == '0')
			{
				if (solve(idx + 1, first, line1, second, line2, 'x', x[idx])) return true;
				if (solve(idx + 1, first, line1, second, line2, 'y', y[idx])) return true;
				return false;
			}

			if (third == 'x') ptr = x;
			else ptr = y;

			if (line3 == ptr[idx]) return solve(idx + 1, first, line1, second, line2, third, line3);
			else return false;
		}
	}

}
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> N;
	for (int i = 0; i < N; ++i) std::cin >> x[i] >> y[i];
	std::cout << solve(0, '0', -1, '0', -1, '0', -1);
}