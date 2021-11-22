#include <iostream>
int cache[10][100];
int solve(int prev, int n)
{
	if (n == 1) return 1;
	if (cache[prev][n]) return cache[prev][n];
	return cache[prev][n] = ((prev == 0 ? 0 : solve(prev - 1, n - 1)) + (prev == 9 ? 0 : solve(prev + 1, n - 1))) % 1000000000;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	int n;
	std::cin >> n;
	int sum = 0;
	for (int i = 1; i <= 9; ++i) sum = (sum + solve(i, n)) % 1000000000;
	std::cout << sum;
}