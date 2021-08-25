#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	//카운팅 정렬
	int arr[10001] = { 0 };
	while (N--)
	{
		int n;
		std::cin >> n;
		++arr[n];
	}

	for (int i = 1; i <= 10000; ++i)
	{
		while (arr[i]--) std::cout << i << '\n';
	}
}