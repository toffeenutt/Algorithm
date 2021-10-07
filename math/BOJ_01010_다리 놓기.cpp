#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    //이항계수의 점화식을 이용
    int triangle[30][30];
    triangle[1][0] = 1;
    triangle[1][1] = 1;
    for (int i = 2; i < 30; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i) triangle[i][j] = 1;
            else triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    int T;
    std::cin >> T;
    while (T--)
    {
        int N, M;
        std::cin >> N >> M;
        std::cout << triangle[M][N] << '\n';
    }
}