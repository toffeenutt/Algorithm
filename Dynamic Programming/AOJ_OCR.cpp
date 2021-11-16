#include <iostream>
#include <string>
#include <cmath>
int m, q, n;
std::string words[500];	//모든 단어의 목록
double B[500], T[500][500], M[500][500];	//확률을 로그값으로 저장(언더플로우가 일어날 수 있으므로)
std::string sentence[100];	//분류기가 인식한 문장 R
int wordIdx[100];	//문장 R의 각 단어의 번호(전체 단어목록에서의 번호)
double cache[500][100];
int choice[500][100];	//답(확률이 가장 높은 문장)을 추적하기 위한 배열

double solve(int prev = 0, int Sidx = 0)
{
	if (Sidx == n) return 0;
	if (cache[prev][Sidx] != 1.0) return cache[prev][Sidx];
	double ret = std::log(0);	//확률 0, -무한대
	int trace = -1;	//확률이 가장 높은 단어의 인덱스
	for (int i = 0; i < m; ++i)	//모든 단어 시도
	{//임의의 원문 Q, 분류기가 인식한 문장 R일때
		//P(Q|R) = P(R|Q) * P(Q) / P(R) 에서 P(R)은 Q가 달라져도 변하지 않으므로
		//P(R|Q) * P(Q) 의 최댓값을 구하면 된다. (P(R|Q) = ㅠM[][], P(Q) = ㅠB[])
		double tmp = (Sidx ? T[prev][i] : B[i]) + M[i][wordIdx[Sidx]];	//로그값이므로 곱하지 않고 더한다.
		if (tmp != std::log(0))
		{
			tmp += solve(i, Sidx + 1);
			if (tmp > ret)
			{
				ret = tmp;
				trace = i;
			}
		}
	}
	choice[prev][Sidx] = trace;
	return cache[prev][Sidx] = ret;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> m >> q;
	for (int i = 0; i < m; ++i) std::cin >> words[i];
	for (int i = 0; i < m; ++i)
	{
		std::cin >> B[i];
		B[i] = std::log(B[i]);
	}
	for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j)
	{
		std::cin >> T[i][j];
		T[i][j] = std::log(T[i][j]);
	}
	for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j)
	{
		std::cin >> M[i][j];
		M[i][j] = std::log(M[i][j]);
	}
	while (q--)
	{
		std::cin >> n;
		for (int i = 0; i < n; ++i)
		{
			std::cin >> sentence[i];
			int j = -1;
			while (sentence[i] != words[++j]);	//단어 번호 찾기
			wordIdx[i] = j;
		}
		for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) cache[i][j] = 1.0;
		solve();
		//추적
		int i = choice[0][0], j = 0;
		while (j != n)
		{
			std::cout << words[i] << ' ';
			i = choice[i][++j];
		}
		std::cout << '\n';
	}
}