#include <iostream>
#include <vector>
int arr[12];
std::vector<int> c;
void combination(int k, int idx = 0)
{
    if (c.size() == 6)
    {
        for (int i = 0; i < 6; ++i) std::cout << c[i] << ' ';
        std::cout << '\n';
        return;
    }
    for (int i = idx; i < k; ++i)
    {
        c.push_back(arr[i]);
        combination(k, i + 1);
        c.pop_back();
    }
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int k;
    std::cin >> k;
    
    while (k)
    {
        for (int i = 0; i < k; ++i) std::cin >> arr[i];
        combination(k);
        std::cout << '\n';
        std::cin >> k;
    }
}