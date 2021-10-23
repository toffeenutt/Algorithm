#include <iostream>
#include <string>
#include <set>
#include <memory.h>
/*
동적계획법을 사용하는경우와 그렇지 않은경우의 시간 차이를 볼 수 있는 입력 예시
1
a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a
2
ahfjsdhfjkdshfkjdshfkdsaojajfjaljaflkajflkdsaljflkaflsaffasfa54656454aafasfsdafsaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb

출력:
ahfjsdhfjkdshfkjdshfkdsaojajfjaljaflkajflkdsaljflkaflsaffasfa54656454aafasfsdafsaaaaaaaaaaaaaaaaaaaa
*/
bool cache[100][100];	//w[i]이후의 문자열과 s[j]이후의 문자열이 매치되지 않는다면 cache[i][j] = true로 캐싱.(중복 연산을 피함)
bool solve(std::string& w, const std::string& s, int i = 0, int j = 0)
{
	while (true)
	{
		if (cache[i][j]) return false;	//이미 계산되어있는 경우 바로 return

		if (i == w.size())
		{
			if (j < s.size())	//w의 끝에 도달했는데 s는 끝이 아니라면 매치되지 않는 경우임.
			{
				cache[i][j] = true;
				return false;
			}
			else return true;	//매치되는 경우
		}
		else if (j == s.size() && w[i] != '*') //w의 끝이 아니고 s의 끝에 도달했는데 w[i]가 *이 아니면 매치되지 않는 경우임.
		{
			cache[i][j] = true;
			return false;
		}

		if (w[i] == '*')	//*이면 *이 0칸~나머지 모든 칸에 대응되는 경우를 모두 재귀호출
		{	
			//한번이라도 solve가 true를 받으면 모든 재귀호출을 true로 리턴하고 프로그램 종료
			for (int q = j; q <= s.size(); ++q) if (solve(w, s, i + 1, q)) return true;	
			cache[i][j] = true;	//for문에서 한번도 return true를 하지 않았다면 매치되지 않은것임.
			return false;
		}
		else if (w[i] != '?' && w[i] != s[j])	//?도 아니고 매치되지 않는경우
		{
			cache[i][j] = true;
			return false;
		}
		else ++i, ++j;	//여기까지 왔으면 w[i]가 ? 이거나 w[i] == s[j] 임. 다음 칸 확인
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
		std::string w;
		std::cin >> w;
		int n;
		std::cin >> n;
		std::set<std::string> s;	//출력시 정렬된 순서로 출력해야 하기 때문에 set 사용
		while (n--)
		{
			std::string tmp;
			std::cin >> tmp;
			s.insert(tmp);
		}

		for (std::set<std::string>::iterator it = s.begin(); it != s.end(); ++it)
		{
			memset(cache, 0, 100 * 100);	//캐시 초기화
			if (solve(w, *it)) std::cout << *it << '\n';
		}
	}
}