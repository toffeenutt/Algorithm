#include <iostream>
#include <string>
#include <algorithm>
std::string s;
int cache[10000];

int solve(int idx = 0)
{
	if (cache[idx]) return cache[idx];

	int ret = 987654321;
	int num = s.size() - idx;	//남은 숫자 수
	if (num == 0) return 0;	//basecase
	if (num > 5) num = 5;
	for (int i = 3; i <= num; ++i)
	{
		bool undecided = false;
		int difficulty = 1;
		for (int j = 1; j < i; ++j)	//난이도 1인지 확인
		{
			if (s[idx] != s[idx + j])
			{
				undecided = true;
				break;
			}
		}

		if (undecided)
		{
			undecided = false;
			int difference = s[idx + 1] - s[idx];	//공차
			for (int j = 2; j < i; ++j)	//등차수열인지 확인(공차가 1이면 난이도 2, 아니면 난이도 5)
			{
				if (s[idx + j - 1] + difference != s[idx + j])
				{
					undecided = true;
					break;
				}
			}
			if (!undecided) difficulty = ((difference == 1 || difference == -1) ? 2 : 5);
			else
			{	//난이도가 4인지 확인
				if (i == 5)
				{
					if (s[idx] == s[idx + 2] && s[idx] == s[idx + 4] && s[idx + 1] == s[idx + 3]) difficulty = 4;
					else difficulty = 10;
				}
				else if (i == 4)
				{
					if (s[idx] == s[idx + 2] && s[idx + 1] == s[idx + 3]) difficulty = 4;
					else difficulty = 10;
				}
				else
				{
					if (s[idx] == s[idx + 2]) difficulty = 4;
					else difficulty = 10;
				}
			}
		}

		ret = std::min(ret, difficulty + solve(idx + i)); //(i개짜리(3~5) 조각의 난이도 + 남은 부분 전체의 최소 난이도) 중 최솟값
	}
	return cache[idx] = ret;
	//num <= 2인 경우 한 조각도 만들수 없으므로 for문에 진입하지 않고 의미없는 큰 값인 987654321을 리턴한다.
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		std::cin >> s;
		for (int i = 0; i <= s.size(); ++i) cache[i] = 0;
		std::cout << solve() << '\n';
	}
}