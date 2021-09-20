#include <iostream>
#include <vector>
#include <algorithm>
int Clock[16];  //시계의 상태
int clock_count[16];    //각 시계의 상태가 변하는 횟수(연결된 버튼들이 눌리는 횟수의 합)
std::vector<std::vector<int>> button = { { 0, 1, 2 },   //button[i] : 버튼에 연결된 시계의 번호들
    { 3, 7, 9, 11 },
    { 4, 10, 14, 15 },  
    { 0, 4, 5, 6, 7 },
    { 6, 7, 8, 10, 12 },
    { 0, 2, 14, 15 },
    { 3, 14, 15 },
    { 4, 5, 7, 14, 15 },
    { 1, 2, 3, 4, 5 },
    { 3, 4, 5, 9, 13 } };
//각 버튼을 4번 이상 누르는 것은 의미가 없다.
//버튼을 누르는 순서는 상관이 없다.
int twelve_clock(int idx = 0, int cnt = 0, int ret = 987654321)
{
    if (cnt >= ret) return ret; //버튼을 누르는 횟수가 기존의 최솟값을 넘은경우 더이상 진행할 필요가 없음(시간단축)
    if (idx == 10)  //모든 버튼의 누르는 횟수를 정했으면
    {
        bool twelve = true;
        for (int i = 0; i < 16; ++i)
        {
            if ((Clock[i] + 3 * (clock_count[i] % 4)) % 12 != 0)    //각 시계의 상태를 바꿔줌
            {
                twelve = false;
                break;
            }
        }
        if (twelve) return cnt; //모든 시계가 12시이면 return cnt;
        return ret; //아니면 기존의 최솟값 return
    }
    for (int i = 0; i < 4; ++i) //각 버튼 i를 0, 1, 2, 3번 눌러봄
    {
        for (int j = 0; j < button[idx].size(); ++j) clock_count[button[idx][j]] += i;
        ret = std::min(ret, twelve_clock(idx + 1, cnt + i, ret));
        for (int j = 0; j < button[idx].size(); ++j) clock_count[button[idx][j]] -= i;
    }
    return ret;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int C;
    std::cin >> C;

    while (C--)
    {
        for (int i = 0; i < 16; ++i)
        {
            std::cin >> Clock[i];
            clock_count[i] = 0;
        }
        int ans = twelve_clock();
        std::cout << (ans != 987654321 ? ans : -1) << '\n';
    }
}