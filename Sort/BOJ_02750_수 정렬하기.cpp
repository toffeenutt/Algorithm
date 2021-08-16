#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	int* arr = new int[N];
	for (int i = 0; i < N; ++i)	//insertion sort
	{
		int n;
		std::cin >> n;
		int j = i;
		for (; j > 0 && arr[j - 1] > n; --j) arr[j] = arr[j - 1];
		arr[j] = n;
	}

	for (int i = 0; i < N; ++i) std::cout << arr[i] << '\n';
}