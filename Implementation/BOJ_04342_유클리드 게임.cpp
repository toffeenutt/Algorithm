#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int a, b;
	std::cin >> a >> b;
	while (a)
	{
		int cnt = 0;
		while (a)
		{
			if (b > a)
			{
				int tmp = a;
				a = b;
				b = tmp;
			}
			++cnt;
			if (a / b >= 2)	break;	//���� 2 �̻��̸� �ش� ���� �÷��̾ ������ �¸� ����.
			a %= b;
		}
		if (cnt % 2) std::cout << "A wins\n";	
		else std::cout << "B wins\n";
		std::cin >> a >> b;
	}
}