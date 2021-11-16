#include <iostream>
int cache[1000001];
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;
	for (int i = 2; i <= n; ++i) cache[i] = 987654321;
	cache[1] = 0;
	for (int i = 1; i < n; ++i)	
	{
		if (i * 2 <= n && cache[i * 2] > cache[i] + 1) cache[i * 2] = cache[i] + 1;
		if (i * 3 <= n && cache[i * 3] > cache[i] + 1) cache[i * 3] = cache[i] + 1;
		if (cache[i + 1] > cache[i] + 1) cache[i + 1] = cache[i] + 1;
	}
	std::cout << cache[n];
}