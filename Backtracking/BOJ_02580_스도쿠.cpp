#include <iostream>
bool sudoku(int board[][9], int r = 0)
{
    bool nine[10];  //board[i][j]에 들어갈 수 있는 숫자(인덱스)를 false로 저장할 배열

    for (int i = r; i < 9; ++i) for (int j = 0; j < 9; ++j)
    {//r부터 시작하면 이미 채워진 행을 건너 뛸 수 있다.
        if (board[i][j] == 0)
        {
            for (int k = 1; k <= 9; ++k) nine[k] = false; //초기화
            for (int k = 0; k < 9; ++k) nine[board[i][k]] = true;   //가로방향 숫자 확인
            for (int k = 0; k < 9; ++k) nine[board[k][j]] = true;   //세로방향 숫자 확인
            for (int q = i / 3 * 3; q < i / 3 * 3 + 3; ++q) //3*3 안에 있는 숫자 확인
            {
                for (int w = j / 3 * 3; w < j / 3 * 3 + 3; ++w)
                {
                    nine[board[q][w]] = true;
                }
            }

            nine[0] = true;
            for (int k = 1; k <= 9; ++k) if (nine[k] == false)  //없는 숫자면 board[i][j]에 넣을 수 있음
            {
                nine[0] = false;
                board[i][j] = k;

                if (sudoku(board, i))   //오답인경우 비우고 다음 가능한 숫자로 진행
                {
                    nine[0] = true;
                    board[i][j] = 0;
                }
                else break; //정답인경우 빠져나감
            }
            if (nine[0]) return true;    //nine[1~9]가 모두 true이면(=board[i][j]에 들어갈 숫자가 하나도 없으면)
            //오답이므로 이전상황으로 돌아감

        }
    }
    return false;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int board[9][9];
    for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) std::cin >> board[i][j];

    sudoku(board);

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j) std::cout << board[i][j] << ' ';
        std::cout << '\n';
    }
}