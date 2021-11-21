#include <iostream>
#include <memory.h>
int N, K, seq[501];
int cache[501];		//cache[idx] = seq[idx]로 시작하는 lis의 길이
long long count[501];	//count[idx] = seq[idx]로 시작하는 lis의 개수
int solve(int prev = 0)	//seq[prev]이후의 수열에 대해 lis의 길이를 리턴하는 함수
{
	if (cache[prev]) return cache[prev];
	int ret = 0;
	count[prev] = 1;
	for (int i = prev + 1; i <= N; ++i) if (seq[prev] < seq[i]) //seq[prev]보다 큰 수만 올 수 있다.
	{
		int tmp = solve(i) + 1;
		if (ret < tmp)	//최댓값을 리턴하기 위해 기존값보다 크면 대체한다.
		{
			ret = tmp;
			count[prev] = count[i];
		}
		else if (ret == tmp)	//ret == tmp이면 lis이므로 lis의 개수 추가(더 큰 tmp가 등장하기 전까지는)
		{
			count[prev] += count[i];	//count[prev] = count[i]의 합(i는 lis인 i만 해당)
			if (count[prev] > 2147483647) count[prev] = 2147483648;	//오버플로우 방지(K가 최대 2147483647이므로)
		}
	}
	return cache[prev] = ret;
}
void kth(int idx, int L, int k)	//k번째 lis를 출력
{
	if (L == -1) return;
	//lis는 항상 사전순서의 역순으로 탐색되므로 사전순서로 탐색하기 위해서는 맨 앞에 올 숫자를 수열의 맨 뒤에서 앞으로 탐색하면서 골라야 한다.
	for (int i = N; i >= idx; --i) if (cache[i] == L && seq[idx - 1] < seq[i])	//이전에 선택한 숫자보다 크고, lis의 길이가 L인 i만 해당(i는 인덱스이다)
	{
		if (count[i] >= k)	//k보다 seq[i]로 시작하는 lis의 개수가 많거나 같으면 seq[i]는 k번째 lis에 있는 숫자가 맞으므로
		{
			std::cout << seq[i] << ' ';	//출력하고
			kth(i + 1, L - 1, k);	//다음 숫자를 찾는다.
			return;
		}
		else k -= count[i];	//그렇지 않으면 다음숫자를 찾는다(count[i]개를 건너뛴다)
	}
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		memset(cache, 0, 501 * sizeof(int));
		std::cin >> N >> K;
		for (int i = 1; i <= N; ++i) std::cin >> seq[i];
		int L = solve();	//L = lis의 길이
		std::cout << L << '\n';
		kth(1, L - 1, K);
		std::cout << '\n';
	}
}