#include <iostream>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	short N, M;
	std::cin >> N >> M;

	char** board = new char* [N];	//2차원 배열 동적할당
	for (int i = 0; i < N; ++i) board[i] = new char[M];

	for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) std::cin >> board[i][j];

	short min = 32;	//칠해야 할 최소 칸의 최대값(초기값)
	for (int i = 0; i < N - 7; ++i) for (int j = 0; j < M - 7; ++j)	//N*M보드 에서 8*8크기 선택할 수 있는 모든 경우의 수
	{//i, j는 각 8*8의 맨 왼쪽 윗칸의 인덱스가 됨
		short Wpaint = 0;	//맨 왼쪽 윗칸을 흰색으로 할 경우 칠해야 할 칸수
		short Bpaint = 0;	//맨 왼쪽 윗칸을 검정색으로 할 경우 칠해야 할 칸수
		for (int q = i; q < i + 8; ++q) for (int w = j; w < j + 8; ++w)	//8*8의 각 칸의 색깔을 확인하는 루프
		{
			if ((q + w) % 2 == 0)	//합이 짝수인 칸(ex 0,0 1,1 2,4 ...)
			{
				if (board[q][w] == 'B') ++Wpaint;	//0,0을 흰색으로 할 경우 짝수칸이 검정색이면 흰색 칠해야 함
				else ++Bpaint;	//0,0을 검정색으로 할 경우 짝수칸이 흰색이면 검정색 칠해야 함
			}
			else	//합이 홀수인 칸(ex 0,1 1,0 3,4...)
			{
				if (board[q][w] == 'W') ++Wpaint;	//홀수칸이 흰색이면 검정색 칠해야 함
				else ++Bpaint;	//홀수칸이 검정색이면 흰색 칠해야 함
			}
		}
		if (Wpaint < min) min = Wpaint;
		if (Bpaint < min) min = Bpaint;
	}
	std::cout << min;
}