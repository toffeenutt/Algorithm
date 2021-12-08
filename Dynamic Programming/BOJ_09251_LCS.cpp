#include <iostream>
#include <string>
#include <algorithm>
std::string A, B;
int cache[1000][1000];
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> A >> B;
	//cache[i][j] 가 A[0:i], B[0:j] 둘의 LCS의 길이 라고 하자.
	//A[i] == B[j]이면 A[0:i-1], B[0:j-1]의 LCS의 뒤에 하나를 추가할 수 있으므로 cache[i-1][j-1] + 1 이다.
	//!= 이면 A[0:i], B[0:j-1] 의 LCS의 길이인 cache[i][j-1] 와 A[0:i-1], B[0:j]의 LCS의 길이인 cache[i-1][j] 중 더 큰 값과 같다.
	for (int i = 0; i < A.size(); ++i) for (int j = 0; j < B.size(); ++j)
	{
		if (A[i] == B[j]) cache[i][j] = (i == 0 || j == 0 ? 1 : cache[i - 1][j - 1] + 1);
		else cache[i][j] = std::max((j == 0 ? 0 : cache[i][j - 1]), (i == 0 ? 0 : cache[i - 1][j]));
	}
	std::cout << cache[A.size() - 1][B.size() - 1];
}