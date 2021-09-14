#include <iostream>
int board_cover(char** board, int h, int w)
{
    int i = 0, j = 0;
    bool find = false;
    for (; i < h; ++i)  //흰 칸중 가장 위에있는 칸, 그중 가장 왼쪽에 있는 칸 찾기
    {
        for (j = 0; j < w; ++j)
        {
            if (board[i][j] == '.')
            {
                find = true;
                break;
            }
        }
        if (find) break;
    }
    if (!find) return 1;   //남은 칸이 없으면 경우의 수 1 추가
    int ret = 0;
    //i, j칸을 포함하여 L자모양 블록으로 덮는 방법 4가지
    //(기준칸의 윗칸, 왼쪽칸은 이미 덮여있거나 덮을 수 없는 칸이므로 경우는 4가지 뿐)
    board[i][j] = '#';
    if (i + 1 < h)
    {
        if (board[i + 1][j] == '.')
        {
            board[i + 1][j] = '#';
            if (j - 1 >= 0 && board[i + 1][j - 1] == '.')
            {
                board[i + 1][j - 1] = '#';
                ret += board_cover(board, h, w);    //1
                board[i + 1][j - 1] = '.';
            }
            if (j + 1 < w)
            {
                if (board[i + 1][j + 1] == '.')
                {
                    board[i + 1][j + 1] = '#';
                    ret += board_cover(board, h, w);    //2
                    board[i + 1][j + 1] = '.';
                }
                if (board[i][j + 1] == '.')
                {
                    board[i][j + 1] = '#';
                    ret += board_cover(board, h, w);    //3
                    board[i][j + 1] = '.';
                }
            }
            board[i + 1][j] = '.';
        }
        if (j + 1 < w && board[i][j + 1] == '.' && board[i + 1][j + 1] == '.')
        {
            board[i][j + 1] = '#';
            board[i + 1][j + 1] = '#';
            ret += board_cover(board, h, w);    //4
            board[i][j + 1] = '.';
            board[i + 1][j + 1] = '.';
        }
    }
    board[i][j] = '.';
    return ret;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    while (N--)
    {
        int H, W;
        std::cin >> H >> W;
        char** board = new char*[H];
        int count = 0;
        for (int i = 0; i < H; ++i)
        {
            board[i] = new char[W];
            for (int j = 0; j < W; ++j)
            {
                std::cin >> board[i][j];
                if (board[i][j] == '.') ++count;
            }
        }
        if (count % 3 == 0) std::cout << board_cover(board, H, W) << '\n';
        else std::cout << 0 << '\n';    //흰 칸의 개수가 3의 배수가 아니면 경우의 수는 0임
    }
}