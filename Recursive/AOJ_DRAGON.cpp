#include <iostream>
#include <string>
std::string solve(int left, int right)	//n세대 전체 문자열에서 출력할 부분 문자열을 리턴. 부분 문자열의 인덱스의 첫값left, 마지막 값right
{
	if (right == 1) return "FX";	//right가 1이면 0세대 이므로 FX리턴
	//문자열은 항상 FX_YF_ (_는 +혹은-) 의 반복으로 구성되고 이는 전 세대의 FX_ 혹은 YF_ 가 치환된 것이다.
	//left, right번째의 문자가 있는 부분(FX_YF_)이 전 세대의 어느 부분(FX_ or YF_)에서 치환된 것인지 계산하여 재귀호출한다.
	int tmpl = (left % 6 <= 4 ? left / 6 * 6 : left), tmpr = (right % 6 <= 4 ? right / 6 * 6 + 4 : right);
	std::string s = solve(tmpl / 2, tmpr / 2 - (right % 6 <= 4 ? 1 : 0));	//전 세대의 문자열에서 필요한 부분만 리턴 받음
	std::string ret;
	for (int i = 0; i < s.size(); ++i)	//전 세대 문자열 s를 이번 세대 문자열 ret에 치환
	{
		if (s[i] == 'X') ret += "X+YF";
		else if (s[i] == 'Y') ret += "FX-Y";
		else ret.push_back(s[i]);
	}
	return ret.substr(left - tmpl, right - left + 1);	//필요한 부분만 리턴
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int C;
	std::cin >> C;
	while (C--)
	{
		int n, p, l;
		std::cin >> n >> p >> l;	//n은 필요 없다.
		std::cout << solve(p - 1, p + l - 2) << '\n';
	}
}