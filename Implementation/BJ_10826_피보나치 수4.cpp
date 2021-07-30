#include <iostream>
#include <iomanip>
/*
10000번째 피보나치 수의 경우 C++에서 가장 큰 수를 저장할 수 있는 타입인 unsigned long long으로도 턱없이 부족하다.
큰 수를 나타내기 위해 unsigned long long A[n] 배열을 만들고,
A[0] 부터 값을 나타내기 시작하여 A[i]이 10^18이 되면 A[i + 1]로 캐리시키는 방식으로 구현하였다.
따라서 큰 수 A는 : (A[0] * 1) + (A[1] * 10^18) + (A[2] * (10^18)^2) + ... 이다.
*/

//unsigned long long이 약 1800경 까지인데
//두 수를 더했을 때 1800경이 넘으면 안된다.
//1800경 / 2 = 900경이지만 10^x 꼴로 해야 하기 때문에 100경이 최대.
#define d 1'000'000'000'000'000'000	//100경, 10^18
#define n 120	//배열의 크기. 100경^120(10^2160)까지 가능. 
//10000번째 피보나치 수가 2090자리수 이므로 10^2090까지는 표현할 수 있어야 한다.

int main()	//4ms
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;
	unsigned long long n1[n] = { 0 };	//초기값 F(0) = 0
	unsigned long long n2[n] = { 1, 0 };	//초기값 F(1) = 1
	unsigned long long tmp[n] = { 0 };

	for (int i = 2; i <= N; ++i)	//F(N)을 구하기
	{
		for (int j = 0; j < n; ++j)	//인덱스 j는 (100^18)^j 을 의미 
		{
			tmp[j] += n1[j] + n2[j];	//n1 = F(i - 2), n2 = F(i - 1)
			if (tmp[j] >= d)	//10^18보다 크거나 같으면 캐리 발생
			{
				++tmp[j + 1];
				tmp[j] -= d;
			}

			n1[j] = n2[j];	
			n2[j] = tmp[j];
			tmp[j] = 0;
		}
 	}

	if (N)
	{
		int i = 0;
		for (; i < n && n2[i] != 0; ++i);
		std::cout << n2[--i];
		--i;
		for (; i >= 0; --i)
		{
			std::cout << std::setw(18) << std::setfill('0') << n2[i];
		}
	}
	else std::cout << 0;
}