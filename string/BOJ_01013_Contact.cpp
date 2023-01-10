#include <iostream>
#include <string>
//정규표현식 라이브러리 사용하면 직접 구현 안해도 됨 //#include <regex>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T;
	std::cin >> T;
	while (T--)
	{
		std::string s;
		std::cin >> s;
		int i = 0;
		int size = s.size();
		bool nomatch = false;
		while (1)
		{
			if (i + 1 < size && s[i] == '0' && s[i + 1] == '1') i += 2;
			else if (i + 2 < size && s[i] == '1' && s[++i] == '0' && s[++i] == '0')
			{
				do
				{
					if (++i == size)
					{
						nomatch = true;
						break;
					}
				} while (s[i] == '0');
				if (nomatch) break;

				while (s[i] == '1')
				{
					if (++i == size) break;
				}
				if (i == size) break;
				if (++i == size)
				{
					nomatch = true;
					break;
				}
				else if (s[i] == '1') ++i;
				else if (s[i - 3] == '1') i -= 2;
				else break;
			}
			else break;
		}

		if (!nomatch && i == size) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
}