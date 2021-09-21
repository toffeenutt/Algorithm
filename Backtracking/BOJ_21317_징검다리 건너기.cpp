#include <iostream>
#include <algorithm> 
int ret = 987654321;
int energy(int* j1, int* j2, int k, int N, int e = 0, int idx = 0)
{
    if (idx == N - 1) return e;
    //이번 단계에서 점프 할 때 에너지가 기존의 최소값보다 크거나 같으면 더이상 진행할 필요 없음(시간단축)
    if (ret > e + j1[idx]) ret = std::min(ret, energy(j1, j2, k, N, e + j1[idx], idx + 1));    //작은 점프
    if (ret > e + j2[idx] && idx < N - 2) ret = std::min(ret, energy(j1, j2, k, N, e + j2[idx], idx + 2));   //큰 점프
    if (ret > e + k && idx < N - 3 && k) ret = std::min(ret, energy(j1, j2, 0, N, e + k, idx + 3));    //매우 큰 점프
    return ret;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;
    
    int* jump1 = new int[N - 1];
    int* jump2 = new int[N - 1];
    int k;
    for (int i = 0; i < N - 1; ++i) std::cin >> jump1[i] >> jump2[i];
    std::cin >> k;
    std::cout << energy(jump1, jump2, k, N);
}