#include <iostream>
#include <string>
int N;
char pixels[64][65];
std::string s;

char areBlackOrWhite(int r, int c, int N)    //모두 검정색인지, 흰색인지, 둘다 아닌지 확인
{
    char first_color = pixels[r][c];
    for (int i = r; i < r + N; ++i) for (int j = c; j < c + N; ++j) if (first_color != pixels[i][j]) return 'f';
    return first_color;
}

void quadTree(int r, int c, int N)
{
    char bow = areBlackOrWhite(r, c, N);
    if (bow != 'f') s += bow;
    else //해당 부분이 모두 검정색 혹은 모두 흰색이 아닌 경우 4구역으로 나누어서 재귀호출(분할정복)
    {
        s += '(';
        quadTree(r, c, N / 2);
        quadTree(r, c + N / 2, N / 2);
        quadTree(r + N / 2, c, N / 2);
        quadTree(r + N / 2, c + N / 2, N / 2);
        s += ')';
    }
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;
    for (int i = 0; i < N; ++i) std::cin >> pixels[i];
    quadTree(0, 0, N);
    std::cout << s;
}