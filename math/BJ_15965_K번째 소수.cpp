#include <iostream>
#include <cmath>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	bool eratosthenes[7368787 + 1] = { 0 };	//eratosthenes[i] == 0 이면 소수
	//에라토스테네스의 체 이용
	for (int j = 4; j <= 7368787; j += 2) eratosthenes[j] = 1;    //2의 배수를 미리 합성수로 처리
	for (int i = 3; i <= sqrt(7368787); ++i)
	{
		if (!eratosthenes[i])	//소수인 경우 그 배수를 모두 합성수로 처리
		{										//i + i인 이유: 홀수인 j에 홀수인 i를 더하면 짝수가 됨
			for (int j = i * i; j <= 7368787; j += i + i) eratosthenes[j] = 1;	//2를제외한 짝수는 이미 합성수로 처리가 되어있으므로
		}									//짝수인경우를 건너 뛰어서 반복 횟수가 1/2가 됨
	}

	int count = 1;
	for (int i = 2; i <= 7368787; ++i)
	{
		if (!eratosthenes[i])
		{
			if (N == count)
			{
				std::cout << i;
				break;
			}
			++count;
		}
	}
}
