#include <iostream>
int N, S;
int arr[20];
int cases = 0;
//1개, 2개, ... N개를 뽑는 모든 경우의 수 확인
void solve(int sum = 0, int idx = 0)
{
    if (sum == S) ++cases;
    for (int i = idx; i < N; ++i) solve(sum + arr[i], i + 1);
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N >> S;
    for (int i = 0; i < N; ++i) std::cin >> arr[i];
    if (S == 0) --cases;    //S가 0인경우 solve함수를 처음 호출할 때 sum == 0이라서 cases에 1이 더해지므로 미리 1을 빼줌
    solve();
    std::cout << cases;
}