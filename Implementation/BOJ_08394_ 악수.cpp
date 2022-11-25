#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin >> n;
	int a = 1;
	int b = 1;
	for (int i = 1; i < n; ++i)
	{
		int c = (a + b) % 10;
		a = b;
		b = c;
	}
	std::cout << b;
}