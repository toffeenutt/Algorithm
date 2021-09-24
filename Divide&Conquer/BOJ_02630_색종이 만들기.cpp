#include <iostream>
int N;
bool paper[128][128];
int white = 0, blue = 0;

char areBlueOrWhite(int r, int c, int N)    //모두 파란색인지, 흰색인지, 둘다 아닌지 확인
{
    bool first_color = paper[r][c];
    for (int i = r; i < r + N; ++i) for (int j = c; j < c + N; ++j) if (first_color != paper[i][j]) return 'f';
    if (first_color) return 'b';
    else return 'w';
}

void CP(int r, int c, int N)
{
    char bow = areBlueOrWhite(r, c, N);
    if (bow == 'w') ++white;
    else if (bow == 'b') ++blue;
    else //해당 부분이 모두 파란색이거나 흰색이 아닌 경우 4구역으로 나누어서 재귀호출(분할정복)
    {
        CP(r, c, N / 2);
        CP(r + N / 2, c, N / 2);
        CP(r, c + N / 2, N / 2);
        CP(r + N / 2, c + N / 2, N / 2);
    }
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) std::cin >> paper[i][j];
    CP(0, 0, N);
    std::cout << white << '\n' << blue;
}