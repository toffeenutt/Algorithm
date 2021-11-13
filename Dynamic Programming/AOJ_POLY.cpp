#include <iostream>
int n;
int cache[101][101];

//이전 줄에 p개의 사각형이 있을 때 그 아래 한 줄 이상에 a개의 사각형을 배치하는 방법의 수
int solve(int p, int a)	//p: 이전 줄의 사각형 개수, a: 남은 사각형 개수
{
	if (a == 0) return 1;
	if (cache[p][a]) return cache[p][a];

	int sum = 0; //이전 줄이 p개일 때 이번 줄이 i개이면 p + i - 1개의 경우가 생기므로 곱해줌. 윗줄에 아무것도 없는경우(처음호출, p = 0) 1을 곱함
	for (int i = 1; i <= a; ++i) sum = (sum + (p ? p + i - 1 : 1) * solve(i, a - i)) % 10000000;
	return cache[p][a] = sum;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		std::cin >> n;
		std::cout << solve(0, n) << '\n';
	}
}