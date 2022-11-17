#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N, feelings;
	std::cin >> N >> feelings;
	
	double gg, gb, bg, bb; //g: good// b: bad
	std::cin >> gg >> gb >> bg >> bb;

	double feelgood = 0, feelbad = 0;
	double pgood = !feelings, pbad = feelings;	//previous

	while (N--)
	{
		feelgood = pgood * gg + pbad * bg;
		feelbad = pgood * gb + pbad * bb;
		pgood = feelgood;
		pbad = feelbad;
	}

	std::cout << (int)(feelgood * 1000  + 0.5) << '\n' << (int)(feelbad * 1000 + 0.5);
}