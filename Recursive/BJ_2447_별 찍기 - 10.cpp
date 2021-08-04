#include <iostream>
#include <string>
//크기 N인 패턴은 크기 N/3인 패턴이 3*3 행렬로 이루어져 있다고 볼 수 있다.
//3*3배열 에서 가운데인 1,1은 공백이다.
//따라서 가운데인 1,1을 제외하고 나머지 부분에 대해 크기 N/3인 패턴을 채우면 된다.
void asterisk(int n, int y, int x, std::string* s)
{
	if (n > 1)
	{
		n /= 3;
		asterisk(n, y + n * 0, x + n * 0, s);
		asterisk(n, y + n * 0, x + n * 1, s);
		asterisk(n, y + n * 0, x + n * 2, s);

		asterisk(n, y + n * 1, x + n * 0, s);
		//1, 1은 공백
		asterisk(n, y + n * 1, x + n * 2, s);

		asterisk(n, y + n * 2, x + n * 0, s);
		asterisk(n, y + n * 2, x + n * 1, s);
		asterisk(n, y + n * 2, x + n * 2, s);
	}
	else
	{
		s[y][x] = '*';
	}

}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::string* s = new std::string[N];

	for (int i = 0; i < N; ++i) s[i] = std::string(N, ' ');

	asterisk(N, 0, 0, s);

	for (int i = 0; i < N; ++i) std::cout << s[i] << '\n';
}