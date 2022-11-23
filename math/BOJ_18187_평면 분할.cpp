#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	std::cin >> N;
	std::cout << N * N / 3 + N + 1;	//규칙찾기. 반복문으로 풀어도 풀림
}