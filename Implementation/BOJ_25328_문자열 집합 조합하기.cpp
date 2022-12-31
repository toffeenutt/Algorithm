#include <iostream>
#include <string>
#include <set>
#include <algorithm>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string str[3];
	std::cin >> str[0] >> str[1] >> str[2];
	int k;
	std::cin >> k;
	
	std::set<std::string> list;
	std::set<std::string> dup;
	for (int i = 0; i < 3; ++i)
	{
		bool combi[17];
		int str_size = str[i].size();
		int fill_zero = str_size - k;
		for (int j = 0; j < fill_zero; ++j) combi[j] = 0;
		for (int j = fill_zero; j < str_size; ++j) combi[j] = 1;
		
		do
		{
			std::string tmp = "";
			int j = 0;
			while (tmp.size() != k)
			{
				if (combi[j] == 1) tmp.push_back(str[i][j]);
				++j;
			}
			if (!list.insert(tmp).second) dup.insert(tmp);
		} while (std::next_permutation(combi, combi + str_size));
	}
	if (dup.size() == 0) std::cout << -1;
	else for (std::set<std::string>::iterator it = dup.begin(); it != dup.end(); ++it) std::cout << *it << '\n';
}