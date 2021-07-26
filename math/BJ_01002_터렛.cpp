#include <iostream>
#include <cmath>
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int T;
	std::cin >> T;
	while (T--)
	{
		int	x1, x2, y1, y2, r1, r2;
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		//각 터렛을 중심으로 반지름이 r인 원을 그렸을때의 교점을 찾으면 된다.
		int c;	//교점의 개수;
		if (x1 == x2 && y1 == y2)	//두 터렛 좌표가 같을 때
		{
			if (r1 == r2) c = -1;	//반지름이 같으면 교점이 무한대
			else c = 0;	//아니면 교점 없음
		}
		else //두 터렛 좌표가 다를 때
		{
			double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));	//두 터렛 사이의 거리 d
			if (r1 < d)	//r1 < d 일 때
			{
				if (r2 < d - r1) c = 0;	//r2 = 0 부터 r2가 점점 커지면서 교점이 0개
				else if (r2 == d - r1) c = 1;	//1개
				else if (r2 < d + r1) c = 2;	//2개
				else if (r2 == d + r1) c = 1;	//1개
				else c = 0;	//0개가 됨
			}
			else if (r1 == d)	//r1 = d 일때
			{
				if (r2 < d + r1) c = 2;
				else if (r2 == d + r1) c = 1;
				else c = 0;
			}
			else //r1 > d 일 때
			{
				if (r2 < r1 - d) c = 0;
				else if (r2 == r1 - d) c = 1;
				else if (r2 < d + r1) c = 2;
				else if (r2 == d + r1) c = 1;
				else c = 0;
			}
		}
		std::cout << c << '\n';
	}
}