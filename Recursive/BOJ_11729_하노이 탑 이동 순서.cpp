#include <iostream>
#include <string>

void hanoi(int n, char origin, char destination, char other, std::string& str)
{//원판이 있는곳: origin, 이동해야하는 곳: destination, 나머지 장대: other
	if (n == 1)
	{
		str.push_back(origin);
		str.push_back(' ');
		str.push_back(destination);
		str.push_back('\n');
	}
	else
	{//n개를 옮기기 위해
		hanoi(n - 1, origin, other, destination, str);	//n-1개를 먼저 옮기고
		str.push_back(origin);	//나머지 한개를 옮기고
		str.push_back(' ');
		str.push_back(destination);
		str.push_back('\n');
		hanoi(n - 1, other, destination, origin, str);	//먼저 옮겼던 n-1개를 다시 옮김
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;
	int k = (1 << N) - 1;	//옮긴 횟수 = 등비수열의 합 a1*(r^n - 1) / (r - 1)
	//2^N = (1 << N) 이다.
	std::cout << k << '\n';

	std::string str;
	hanoi(N, '1', '3', '2', str);

	std::cout << str;
	//hanoi함수 안에서 옮길 때마다 따로 출력하는것 보다 한번에 문자열에 모아서 출력하는게 훨씬 빨랐음.
}