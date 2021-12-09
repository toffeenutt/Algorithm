#include <iostream>
#include <algorithm>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, arr[100000];
	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> arr[i];
	int sum = -1000, psum = -1000;
	for (int i = 0; i < n; ++i)
	{//psum == arr[0:i]에서 arr[i]를 포함하는 최대인 연속합
		psum = std::max(psum + arr[i], arr[i]);
		sum = std::max(sum, psum);
	}//sum == arr[0:i] 에서 최대인 연속합
	std::cout << sum;
}