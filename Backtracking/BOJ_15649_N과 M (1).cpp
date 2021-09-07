#include <iostream>
#include <vector>
void permutation(std::vector<int>& p, bool* inp, int n, int m)
{
    if (p.size() == m)  //수열이 완성되면 출력
    {
        for (int i = 0; i < m; ++i) std::cout << p[i] << ' ';
        std::cout << '\n';
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (!inp[i])    //i가 수열에 없는경우만 새로 추가
            {
                inp[i] = true;
                p.push_back(i);
                permutation(p, inp, n, m);
                p.pop_back();
                inp[i] = false;
            }
        }
    }
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N, M;
    std::cin >> N >> M;

    std::vector<int> p; //순열중 한가지 경우의 수열을 저장할 벡터
    bool* is_in_permutation = new bool[N + 1]; //각 수를 인덱스로 하여 수열에 들어있는지 확인하는 배열
    for (int i = 1; i <= N; ++i) is_in_permutation[i] = false;
    permutation(p, is_in_permutation, N, M);
}