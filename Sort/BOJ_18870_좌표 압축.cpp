#include <iostream>
#include <algorithm>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int N;
	std::cin >> N;

	int* arr = new int[N];
	int* sorted_arr = new int[N];
	for (int i = 0; i < N; ++i)
	{
		std::cin >> arr[i];
		sorted_arr[i] = arr[i];
	}
	std::sort(sorted_arr, sorted_arr + N);	//1. 정렬 //O(nlogn)

	int i = 0;
	for (int j = 0, k = 1; j + k < N;)	//2. 중복되는 element를 제거 (unique함수와 같음) //O(n)
	{
		if (sorted_arr[j] == sorted_arr[j + k]) ++k;
		else
		{
			j += k;
			sorted_arr[++i] = sorted_arr[j];
			k = 1;
		}
	}

	for (int j = 0; j < N; ++j)
	{
		int low = 0, high = i;
		int mid = (low + high) / 2;
		while (sorted_arr[mid] != arr[j])	//3. 정렬 되어있으므로 이진탐색
		{
			if (sorted_arr[mid] > arr[j]) high = mid - 1;
			else low = mid + 1;
			mid = (low + high) / 2;
		}
		std::cout << mid << ' ';
	}//정렬 후 중복을 제거한 배열의 각 element에 대한 index가 문제의 답
}