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
	/*0~i까지의 누적합을 sum[i] 라 할 때 
	* i~j의 구간합은 sum[j]-sum[i-1]이다.
	* (sum[j]-sum[i-1]) mod M = 0인 모든 i, j쌍의 개수를 구해야 한다.
	* sum[j] mod M = sum[i-1] mod M 이므로 누적합 mod M 이 같은 것의 개수를 세면 된다.
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