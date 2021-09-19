#include <iostream>
#include <algorithm>
int chooseup(int** stats, int N, int idx = 1, int cnt = 1)
{//stats[i][i] = 1이면 i는 스타트팀, 0이면 링크팀인것으로 활용(별도의 bool 배열 필요 없음)
    if (cnt == N / 2)   //팀이 구성 되면
    {
        int start = 0, link = 0;
        for (int i = 0; i < N; ++i)
        {
            if (stats[i][i]) for (int j = i + 1; j < N; ++j)    //i가 스타트팀일때
            {
                if (stats[j][j]) start += stats[i][j] + stats[j][i];    //j가 스타트팀이면 능력치를 더함
            }
            else for (int j = i + 1; j < N; ++j)    //i가 링크팀일때
            {
                if (!stats[j][j]) link += stats[i][j] + stats[j][i];    //j가 링크팀이면 능력치를 더함
            }
        }
        return (start > link ? start - link : link - start);    //둘의 차의 절대값 리턴
    }
    int min = 987654321;
    for (int i = idx; i < N; ++i)
    {
        stats[i][i] = 1;
        min = std::min(min, chooseup(stats, N, i + 1, cnt + 1));
        stats[i][i] = 0;
    }
    return min;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int** stats = new int* [N];
    for (int i = 0; i < N; ++i)
    {
        stats[i] = new int[N];
        for (int j = 0; j < N; ++j) std::cin >> stats[i][j];
    }

    stats[0][0] = 1;    //스타트 팀에 0을 반드시 포함시킴(중복을 피하기 위함)
    //총 6명일 때 예를들어
    //스타트팀 0, 1, 2 링크팀 3, 4, 5 인 경우와
    //링크팀 0, 1, 2 스타트팀 3, 4, 5 인 경우는 같은 경우이므로
    //스타트 팀에 한명을 항상 뽑아두면 중복이 발생하지 않음
    std::cout << chooseup(stats, N);
}