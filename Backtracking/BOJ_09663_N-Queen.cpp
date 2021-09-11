#include <iostream>
#include <cmath>
#define empty -987654321
int NQ(int* horizontal, int N, int vertical = 0)    //horizontal의 인덱스: 수평좌표, vertical: 수직좌표
{
    if (N == vertical) return 1;    //퀸이 N개 놓이면 경우의 수 1 추가

    int cases = 0;  //경우의 수
    for (int i = 0; i < N; ++i)
    {
        if (horizontal[i] == empty) //empty가 아니면 건너 뜀(해당 열에 퀸이 있으면 건너 뜀)
        {
            bool dup = false;
            for (int j = 0; j < N; ++j) if (abs(i - j) == abs(vertical - horizontal[j]))
            {//대각선 위치에 이미 퀸이 있으면 퀸을 놓을 수 없음(수평, 수직좌표끼리의 차의 절대값이 각각 같으면 대각선위치)
                dup = true;
                break;
            }
            if (!dup)   //empty가  아니고, 행, 열, 대각선상에 중복도 없을 때 퀸을 놓음
            {
                horizontal[i] = vertical; //(vertical, i) 에 퀸 놓음
                cases += NQ(horizontal, N, vertical + 1);   //다음 행에서 퀸 놓을 곳 찾기
                horizontal[i] = empty;  //돌아온 후 비워줌(백트래킹)
            }
        }
    }

    return cases;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int* horizontal = new int[N];   //horizontal의 index는 수평좌표(열)를 나타내고, element에는 (퀸이 있는 경우)수직좌표(행)를 저장함
    for (int i = 0; i < N; ++i) horizontal[i] = empty;  //element가 empty(-987654321)이면 퀸이 없는 빈 열

    std::cout << NQ(horizontal, N);
}