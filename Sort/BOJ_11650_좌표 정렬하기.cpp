#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	int* x = new int[N + 1];
	int* y = new int[N + 1];
	
	//x좌표를 기준으로 heap sort를 하고, x좌표가 같은 경우 y좌표를 비교한다.
	for (int i = 1; i <= N; ++i)
	{
		std::cin >> x[i] >> y[i];
		
		for (int j = i; j > 1 && x[j / 2] <= x[j]; j /= 2)	//max heap, upheap
		{
			//x좌표가 같은경우, 
			if (x[j / 2] == x[j] && y[j / 2] > y[j]) break;	//y좌표에서 부모가 자식보다 크면 heap order 맞으므로 break

			x[0] = x[j / 2];
			x[j / 2] = x[j];
			x[j] = x[0];

			y[0] = y[j / 2];
			y[j / 2] = y[j];
			y[j] = y[0];
		}
	}

	for (int i = N; i > 0; --i)	//heap sort, downheap
	{
		x[0] = x[i];
		x[i] = x[1];
		x[1] = x[0];

		y[0] = y[i];
		y[i] = y[1];
		y[1] = y[0];

		int j = 1;
		while (j * 2 < i)
		{
			if (j * 2 == i - 1) //left child만 있는 경우
			{
				if (x[j] <= x[j * 2])
				{
					if (x[j] == x[j * 2] && y[j] > y[j * 2]) break;

					x[0] = x[j];
					x[j] = x[j * 2];
					x[j * 2] = x[0];

					y[0] = y[j];
					y[j] = y[j * 2];
					y[j * 2] = y[0];

					j *= 2;
				}
				else break;
			}
			else //자식이 둘 다 있는 경우
			{
				int tmp;
				if (x[j * 2] > x[j * 2 + 1]) tmp = j * 2;
				else if (x[j * 2] < x[j * 2 + 1]) tmp = j * 2 + 1;
				else if (y[j * 2] > y[j * 2 + 1]) tmp = j * 2;	//x좌표가 같으면 y좌표로 비교
				else tmp = j * 2 + 1;

				if (x[j] <= x[tmp])
				{
					if (x[j] == x[tmp] && y[j] > y[tmp]) break;

					x[0] = x[j];
					x[j] = x[tmp];
					x[tmp] = x[0];

					y[0] = y[j];
					y[j] = y[tmp];
					y[tmp] = y[0];

					j = tmp;
				}
				else break;
			}
		}
	}

	for (int i = 1; i <= N; ++i) std::cout << x[i] << ' ' << y[i] << '\n';
}