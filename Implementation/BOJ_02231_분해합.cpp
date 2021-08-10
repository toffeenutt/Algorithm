#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	int tmp = N;
	int i = 0;	//N이 몇 자리수인지 구함
	for (; tmp != 0; ++i) tmp /= 10;

	//어떤 생성자 M으로부터 생성되는 분해합의 최댓값은
	//M + M의 자리수 * 9 이다.

	int j = N - i * 9;	//생성자가 N - N의 자리수 * 9 미만에는 있을 수 없으므로 N - i * 9 부터 시작
	if (j < 0) j = 0;
	for (; j < N; ++j)
	{
		tmp = j;
		int sum = j;
		while (tmp)	//각 자리수의 합을 구하는 반복문
		{
			sum += tmp % 10;
			tmp /= 10;
		}
		if (sum == N)	//j가 생성자이면 출력하고 끝냄
		{
			std::cout << j;
			return 0;
		}
	}
	std::cout << 0;
	return 0;
}