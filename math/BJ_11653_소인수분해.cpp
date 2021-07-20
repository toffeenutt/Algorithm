//N을 소인수분해 하기

#include <iostream>
#include <cmath>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	while (true)
	{	//아래의 루프에서 짝수를 피하기 위해 먼저 소인수 2를 제거
		if (N % 2 == 0)
		{
			std::cout << 2 << '\n';
			N /= 2;
		}
		else break;
	}
	int i = 3;
	while (N != 1)
	{
		if (i > sqrt(N))	//i가 sqrt(N)보다 크면 N은 소수이므로 출력후 끝냄
		{	//이 if문이 없을 경우 i == N일때까지 반복해야 해서 오래걸림
			std::cout << N << '\n';
			break;
		}

		if (N % i == 0)	//홀수로 나누어 떨어지면 출력
		{	//(i가 소수가 아닐수도 있지만 그경우는 이미 나머지가 0이 아님)
			std::cout << i << '\n';
			N /= i;
		}
		else i += 2;	//더이상 나누어 떨어지지 않으면 다음 홀수로 진행
	}
}