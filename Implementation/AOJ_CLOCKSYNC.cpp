#include <iostream>
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int C;
    std::cin >> C;

    /*
    각 버튼을 4번 이상 누르는 것은 의미가 없다.
    버튼을 누르는 순서는 결과에 영항을 미치지 않는다. 이므로 
    4^10의 경우의수를 모두 탐색하는 완전탐색 풀이를 의도하고 낸 문제이지만

    문제에서 주어진 버튼-시계 조합의 경우
    시계에 연결된 버튼이 하나밖에 없는 시계의 버튼을 찾아서
    그 버튼을 3회 이하로 적절히 누르고 지우는(더이상 누르지않는) 동작을 10번만(버튼 개수) 수행하면
    최소 횟수를 구할 수 있다.

    그리고 연결된 버튼들이 모두 같은 시계가 두 개 이상 있는 경우
    시계들의 상태(시간)이 다르면 모두 12시로 맞추는게 불가능한 경우이므로 -1을 출력하면 된다.
    ex) 초기 입력의 8번, 12번 시계의 시간이 다르면 4번버튼을 아무리 눌러도 동시에 12시가 될 수 없다.
    14, 15번 시계의 시간이 다르면 그에 연결된 어떤 버튼을 눌러도 동시에 12시가 될 수 없다.
    */

    int Clock[16];
    while (C--)
    {
        for (int i = 0; i < 16; ++i)
        {
            std::cin >> Clock[i];
        }
        if (Clock[8] != Clock[12] || Clock[14] != Clock[15]) std::cout << "-1\n";
        else
        {
            int cnt = 0;
            while (Clock[8] % 12 != 0)  //4번버튼
            {
                Clock[6] += 3;
                Clock[7] += 3;
                Clock[8] += 3;
                Clock[10] += 3;
                Clock[12] += 3;
                ++cnt;
            }
            while (Clock[6] % 12 != 0)  //3
            {
                Clock[0] += 3;
                Clock[4] += 3;
                Clock[5] += 3;
                Clock[6] += 3;
                Clock[7] += 3;
                ++cnt;
            }
            while (Clock[10] % 12 != 0) //2
            {
                Clock[4] += 3;
                Clock[10] += 3;
                Clock[14] += 3;
                Clock[15] += 3;
                ++cnt;
            }
            while (Clock[11] % 12 != 0) //1
            {
                Clock[3] += 3;
                Clock[7] += 3;
                Clock[9] += 3;
                Clock[11] += 3;
                ++cnt;
            }
            while (Clock[7] % 12 != 0) //7
            {
                Clock[4] += 3;
                Clock[5] += 3;
                Clock[7] += 3;
                Clock[14] += 3;
                Clock[15] += 3;
                ++cnt;
            }
            if (Clock[9] % 12 != Clock[13] % 12)
            {
                std::cout << "-1\n";
                continue;
            }
            while (Clock[9] % 12 != 0) //9
            {
                Clock[3] += 3;
                Clock[4] += 3;
                Clock[5] += 3;
                Clock[9] += 3;
                Clock[13] += 3;
                ++cnt;
            }
            if (Clock[4] % 12 != Clock[5] % 12)
            {
                std::cout << "-1\n";
                continue;
            }
            while (Clock[4] % 12 != 0) //8
            {
                Clock[1] += 3;
                Clock[2] += 3;
                Clock[3] += 3;
                Clock[4] += 3;
                Clock[5] += 3;
                ++cnt;
            }
            while (Clock[1] % 12 != 0) //0
            {
                Clock[0] += 3;
                Clock[1] += 3;
                Clock[2] += 3;
                ++cnt;
            }
            while (Clock[0] % 12 != 0) //5
            {
                Clock[0] += 3;
                Clock[2] += 3;
                Clock[14] += 3;
                Clock[15] += 3;
                ++cnt;
            }
            if (Clock[3] % 12 != Clock[14] % 12 || Clock[14] % 12 != Clock[15] % 12)
            {
                std::cout << "-1\n";
                continue;
            }
            while (Clock[3] % 12 != 0) //6
            {
                Clock[3] += 3;
                Clock[14] += 3;
                Clock[15] += 3;
                ++cnt;
            }
            std::cout << cnt << '\n';
        }
    }
}