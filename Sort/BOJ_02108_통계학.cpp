#include <iostream>
#include <cmath>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	int* arr = new int[N + 1];
	int sum = 0;
	int min = 4000;
	int max = -4000;

	int positive[4001] = { 0 };	//최빈값을 셀 배열
	int negative[4001] = { 0 };	//음수도 있음

	for (int i = 1; i <= N; ++i)
	{
		std::cin >> arr[i];
		sum += arr[i];
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];

		if (arr[i] >= 0) ++positive[arr[i]];	//입력값을 index로 하여 개수 세기
		else ++negative[abs(arr[i])];

		for (int j = i; j > 1 && arr[j / 2] < arr[j]; j /= 2)	//max heap, upheap
		{
			arr[0] = arr[j / 2];
			arr[j / 2] = arr[j];
			arr[j] = arr[0];
		}
	}

	for (int i = N; i > 0; --i)	//heap sort, downheap
	{
		arr[0] = arr[i];
		arr[i] = arr[1];
		arr[1] = arr[0];

		int j = 1;
		while (j * 2 < i)
		{
			if (j * 2 == i - 1) //left child만 있는 경우
			{
				if (arr[j] < arr[j * 2])
				{
					arr[0] = arr[j];
					arr[j] = arr[j * 2];
					arr[j * 2] = arr[0];

					j *= 2;
				}
				else break;
			}
			else //자식이 둘 다 있는 경우
			{
				int tmp;
				if (arr[j * 2] > arr[j * 2 + 1]) tmp = j * 2;
				else tmp = j * 2 + 1;

				if (arr[j] < arr[tmp])
				{
					arr[0] = arr[j];
					arr[j] = arr[tmp];
					arr[tmp] = arr[0];

					j = tmp;
				}
				else break;
			}
		}
	}

	int mode;
	int mode_counter = -1;
	bool first = true;
	for (int i = 4000; i > 0; --i) //-4000부터 -1까지 최빈값 찾기
	{
		if (first && negative[i] == mode_counter)	//최빈값이 2개 이상인 경우
		{//2번째로 작은 값을 출력해야 하기 때문에 2번째 값으로 변경
			mode = -1 * i;
			first = false;
		}
		if (negative[i] > mode_counter)
		{
			mode_counter = negative[i];
			mode = -1 * i;
			first = true;
		}
	}
	for (int i = 0; i < 4001; ++i)	//0부터 4000까지 최빈값 찾기
	{
		if (first && positive[i] == mode_counter)
		{
			mode = i;
			first = false;
		}
		if (positive[i] > mode_counter)
		{
			mode_counter = positive[i];
			mode = i;
			first = true;
		}
	}

	std::cout << round(sum / (double)N) << '\n';	//평균
	std::cout << arr[N / 2 + 1] << '\n';	//중앙값
	std::cout << mode << '\n';	//최빈값
	std::cout << max - min << '\n';	//범위
}