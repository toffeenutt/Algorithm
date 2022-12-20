#include <iostream>
long long cnt[1000];
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, M;
	std::cin >> N >> M;
	int sum = 0;
	/*0~i������ �������� sum[i] �� �� �� 
	* i~j�� �������� sum[j]-sum[i-1]�̴�.
	* (sum[j]-sum[i-1]) mod M = 0�� ��� i, j���� ������ ���ؾ� �Ѵ�.
	* sum[j] mod M = sum[i-1] mod M �̹Ƿ� ������ mod M �� ���� ���� ������ ���� �ȴ�.
	*/
	for (int i = 0; i < N; ++i)
	{
		int a;
		std::cin >> a;
		sum = (sum + a) % M;
		++cnt[sum];
	}
	long long ans = cnt[0];
	for (int i = 0; i < M; ++i)
	{
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	std::cout << ans;
}