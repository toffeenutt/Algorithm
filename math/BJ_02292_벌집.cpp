#include <iostream>
#include <cmath>
int main()
{
	int N;
	std::cin >> N;
	if (N == 1) std::cout << 1;
	else std::cout << (int)(-1 + sqrt(1 + 4 * 2 * ((N - 2) / 6))) / 2 + 2;
	//등차수열의 합->2차방정식->근의 공식을 문제에 맞게 변형
}