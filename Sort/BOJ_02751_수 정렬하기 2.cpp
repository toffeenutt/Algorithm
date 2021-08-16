#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	int* arr = new int[N + 1];
	for (int i = 1; i <= N; ++i)	//min heap
	{
		std::cin >> arr[i];
		for (int j = i; j > 1 && arr[j / 2] > arr[j]; j /= 2)	//upheap
		{
			arr[0] = arr[j / 2];
			arr[j / 2] = arr[j];
			arr[j] = arr[0];			
		}
	}
	
	for (int i = N; i > 0; --i)
	{
		std::cout << arr[1] << '\n';
		arr[1] = arr[i];
		for (int j = 1; j * 2 <= i - 1; )	//downheap
		{
			if (j * 2 == i - 1)	//left child만 있는 경우
			{
				if (arr[j] > arr[j * 2])	//swap with left child
				{
					arr[0] = arr[j];
					arr[j] = arr[j * 2];
					arr[j * 2] = arr[0];
					j *= 2;
				}
				else break;
			}
			else if (arr[j] > arr[j * 2])	//둘다 있는 경우
			{
				if (arr[j * 2] < arr[j * 2 + 1])	//swap with left child
				{
					arr[0] = arr[j];
					arr[j] = arr[j * 2];
					arr[j * 2] = arr[0];
					j *= 2;
				}
				else //swap with right child
				{
					arr[0] = arr[j];
					arr[j] = arr[j * 2 + 1];
					arr[j * 2 + 1] = arr[0];
					j = j * 2 + 1;
				}
			}
			else if (arr[j] > arr[j * 2 + 1])	//swap with right child
			{
				arr[0] = arr[j];
				arr[j] = arr[j * 2 + 1];
				arr[j * 2 + 1] = arr[0];
				j = j * 2 + 1;
			}
			else break;
		}
	}
}