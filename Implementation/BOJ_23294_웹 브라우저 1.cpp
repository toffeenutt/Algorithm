#include <iostream>
#include <list>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, Q, C;
	std::cin >> N >> Q >> C;
	int size[2001];
	for (int i = 1; i <= N; ++i) std::cin >> size[i];
	char task;
	std::list<int> back, front;
	int current = -1;
	int bsize = 0, fsize = 0;
	while (Q--)
	{
		std::cin >> task;
		switch (task)
		{
		case 'B':
			if (!back.empty())
			{
				front.push_front(current);
				fsize += size[current];
				current = back.front();
				back.pop_front();
				bsize -= size[current];
			}
			break;
		case 'F':
			if (!front.empty())
			{
				back.push_front(current);
				bsize += size[current];
				current = front.front();
				front.pop_front();
				fsize -= size[current];
			}
			break;
		case 'A':
			int i;
			std::cin >> i;
			front.clear();
			fsize = 0;
			if (current != -1)
			{
				back.push_front(current);
				bsize += size[current];
			}
			current = i;
			while (bsize + size[current] + fsize > C)
			{
				bsize -= size[back.back()];
				back.pop_back();
			}
			break;
		case 'C':
			std::list<int>::iterator it = back.begin();
			while (it != back.end())
			{
				int v = *it;
				std::list<int>::iterator tmp = it;
				if (++it != back.end() && v == *it)
				{
					bsize -= size[*it];
					back.erase(it);
					it = tmp;
				}
			}
			break;
		}
	}
	std::cout << current << '\n';
	if (back.empty()) std::cout << -1;
	else
	{
		std::list<int>::iterator b = back.begin();
		while (b != back.end()) std::cout << *b++ << ' ';
	}
	std::cout << '\n';
	if (front.empty()) std::cout << -1;
	else
	{
		std::list<int>::iterator f = front.begin();
		while (f != front.end()) std::cout << *f++ << ' ';
	}
	std::cout << '\n';
}