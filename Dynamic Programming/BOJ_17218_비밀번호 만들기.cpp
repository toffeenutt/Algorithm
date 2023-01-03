#include <iostream>
#include <string>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string a, b;
	std::cin >> a >> b;

	std::string cache[41][41];
	for (int i = 0; i < 41; ++i) cache[i][0] = cache[0][i] = "";
	int asize = a.size(), bsize = b.size();
	a = '0' + a;	//index 접근 cache와 같게 하기 위함
	b = '0' + b;
	for (int i = 1; i <= asize; ++i) for (int j = 1; j <= bsize; ++j)
	{
		if (a[i] == b[j]) cache[i][j] = cache[i - 1][j - 1] + a[i];
		else cache[i][j] = (cache[i][j-1].size() > cache[i-1][j].size() ? cache[i][j - 1] : cache[i - 1][j]);
	}
	std::cout << cache[asize][bsize];
}