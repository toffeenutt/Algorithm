#include <iostream>
#include <algorithm>
#include <string.h>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin >> T;
	while (T--)
	{
		int N;
		std::cin >> N;
		int red_cnt[1000];
		memset(red_cnt, 0, sizeof(int) * N);
		for (int i = 0; i < N; ++i) for (int j = i + 1; j < N; ++j)
		{
			int tube;
			std::cin >> tube;
			red_cnt[i] += tube;
			red_cnt[j] += tube;
		}
		int two_colored = 0;	//�� ������ ���� �ٸ� ���� ����
		for (int i = 0; i < N; ++i) two_colored += red_cnt[i] * (N-1 - red_cnt[i]);

		std::cout << (N * (N - 1) * (N - 2) / 6) - (two_colored / 2) << '\n';	//��ü �ﰢ���� ���� - �ܻ��� �ƴ� �ﰢ���� ����
		//�ܻ��� �ƴ� �ﰢ���� �ݵ�� �� ������ ���� �ٸ� ���� 2�� ���´�.
		//���� �ܻ��� �ƴ� �ﰢ���� ���� = two_colored / 2
	}
}