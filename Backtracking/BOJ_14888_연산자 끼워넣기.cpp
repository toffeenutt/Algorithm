#include <iostream>
int max = -1'000'000'000, min = 1'000'000'000;
void cal(int* seq, int add, int sub, int mul, int div, int ans, int cnt = 1)
{
    bool finish = true;
    if (add)
    {
        cal(seq, add - 1, sub, mul, div, ans + seq[cnt], cnt + 1);
        finish = false;
    }
    if (sub)
    {
        cal(seq, add, sub - 1, mul, div, ans - seq[cnt], cnt + 1);
        finish = false;
    }
    if (mul)
    {
        cal(seq, add, sub, mul - 1, div, ans * seq[cnt], cnt + 1);
        finish = false;
    }
    if (div)
    {
        cal(seq, add, sub, mul, div - 1, ans / seq[cnt], cnt + 1);
        finish = false;
    }

    if (finish) //연산자가 모두 0이면 한 가지 경우 완료
    {
        if (max < ans) max = ans;
        if (min > ans) min = ans;
    }
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;
    int* sequence = new int[N];
    for (int i = 0; i < N; ++i) std::cin >> sequence[i];
    int add, sub, mul, div;
    std::cin >> add >> sub >> mul >> div;

    cal(sequence, add, sub, mul, div, sequence[0]);

    std::cout << max << '\n' << min;    
}