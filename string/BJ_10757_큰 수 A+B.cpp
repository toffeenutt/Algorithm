#include <iostream>
#include <string>
#include <algorithm>
//큰 수 계산, 문자열로 처리

std::string operator+(std::string s1, std::string s2)	//+연산자 오버로딩
{
	std::reverse(s1.begin(), s1.end());	//뒤집어서 계산해야 인덱스 접근 쉬움
	std::reverse(s2.begin(), s2.end());

	std::string& s3 = s1.size() > s2.size() ? s1 : s2;	//둘중 긴 것을 s3로 참조
	char carry = 0;
	int i = 0;
	char tmp;
	for (; i < s1.size() && i < s2.size(); ++i)	//뒤집힌 문자열이 12345, 123 이면 123 까지의 계산
	{
		tmp = carry + s1[i] - '0' + s2[i] - '0';
		if (tmp > 9)
		{
			carry = 1;
			tmp -= 10;
		}
		else carry = 0;
		s3[i] = (tmp + '0');
	}

	for (; i < s3.size(); ++i)	//나머지 부분 45에 대한 계산
	{
		tmp = carry + s3[i] - '0';
		if (tmp == 10)
		{
			carry = 1;
			tmp = 0;
		}
		else carry = 0;
		s3[i] = (tmp + '0');
	}
	if (carry) s3.push_back('1');	//마지막 캐리 있을경우 추가
	
	std::reverse(s3.begin(), s3.end());
	return s3;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::string a, b;
	std::cin >> a >> b;
	std::cout << a + b;
}