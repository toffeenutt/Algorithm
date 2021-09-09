#include <iostream>
#include <vector>
void permutation(std::vector<int>& p, int n, int m)
{
    if (p.size() == m)  //수열이 완성되면 출력
    {
        for (int i = 0; i < m; ++i) std::cout << p[i] << ' ';
        std::cout << '\n';
    }
    else
    {
        for (int i = (p.empty() ? 1 : p.back() + 1); i <= n; ++i)   //p의 마지막 값보다 1 큰 수만 넣을 수 있으므로
        {
            p.push_back(i);
            permutation(p, n, m);
            p.pop_back();
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
    permutation(p, N, M);
}