#include <iostream>
int ApowBmodC(int a, int b, int c)
{
	if (b == 1) return a;
	if (b % 2) return (long long)a * ApowBmodC(a, b - 1, c) % c;	//b가 홀수일경우 a * a^(b-1)
	long long tmp = ApowBmodC(a, b / 2, c);	//b가 짝수일경우 a^(b/2) * a^(b/2);
	return tmp * tmp % c;
}
int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int A, B, C;
	std::cin >> A >> B >> C;
	std::cout << ApowBmodC(A % C, B, C);
}