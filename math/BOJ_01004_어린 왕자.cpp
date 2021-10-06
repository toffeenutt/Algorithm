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
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		int n;
		std::cin >> n;
		int cnt = 0;	//출발점만 포함하는 원 + 도착점만 포함하는 원
		while (n--)
		{
			int cx, cy, r;
			std::cin >> cx >> cy >> r;
			bool both = false;
			if (std::pow(cx - x1, 2) + std::pow(cy - y1, 2) < std::pow(r, 2))
			{//원의 중심과 출발점 사이의 길이가 반지름보다 짧으면 원 안에 있는것. sqrt사용할 필요 없음(r을 제곱해서 비교)
				++cnt;
				both = true;
			}
			if (std::pow(cx - x2, 2) + std::pow(cy - y2, 2) < std::pow(r, 2))
			{//도착점
				if (both) --cnt;	//출발점, 도착점을 둘다 포함할 경우 진입/이탈이 필요 없으므로 1을 빼줌
				else ++cnt;
			}
		}
		std::cout << cnt << '\n';
	}
}