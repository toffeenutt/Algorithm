#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	std::cin >> N;
	std::cout << N * N / 3 + N + 1;	//��Ģã��. �ݺ������� Ǯ� Ǯ��
}