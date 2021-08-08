#include <iostream>
#include <cmath>
int main()
{
	int N;
	std::cin >> N;
	int a = ceil((-1 + sqrt(1 + 8 * N)) / 2);
	int b = N - (a * (a - 1) / 2) - 1;
	if (a % 2 == 0) std::cout << 1 + b << '/' << a - b;
	else std::cout << a - b << '/' << 1 + b;
}