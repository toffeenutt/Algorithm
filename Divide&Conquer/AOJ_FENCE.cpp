#include <iostream>
#include <algorithm>
int arr[20000];
int rectangle(int left, int right)  //분할정복 풀이
{
    if (left == right) return arr[left];    //base case, 한 칸인 경우 그 칸의 높이 = 넓이
    //울타리 n개를 절반으로 나누었을 때 넓이가 최대인 직사각형은
    //다음의 세가지 경우 중 하나에 있다.
    //mid를 기준으로
    //1. 왼쪽 부분(mid포함)
    //2. 오른쪽 부분(mid제외)
    //3. mid와 mid + 1을 포함하는 부분(가운데 두 칸을 반드시 포함하는 부분)

    //3번경우부터 구함(1, 2번경우는 재귀호출)
    int mid = (left + right) / 2;
    int min_height = arr[mid] < arr[mid + 1] ? arr[mid] : arr[mid + 1];
    //mid칸과 mid + 1칸 중 더 낮은 높이를 기준으로 잘라야 직사각형이 됨
    int max_area = min_height * 2;
    int i = mid, j = mid + 1;
    //가운데를 기준으로 왼쪽칸이 더 높으면 왼쪽으로, 오른쪽칸이 더 높으면 오른쪽으로 한 칸씩 넓힘(높은 칸으로 가야 최대넓이를 놓치지 않음)
    //양 끝에 도달할 때 까지 반복하면 직사각형의 최대넓이를 알 수 있다.
    while (i != left || j != right)
    {
        int k;
        if (i == left) k = ++j; //왼쪽으로 더이상 갈 수 없는 경우 오른쪽으로 진행
        else if (j == right) k = --i;   //오른쪽으로 더이상 갈 수 없는 경우 왼쪽으로 진행
        else if (arr[i - 1] > arr[j + 1]) k = --i;  //왼쪽이 더 높은 경우 왼쪽으로
        else k = ++j;   //오른쪽으로

        min_height = std::min(arr[k], min_height);  //가장 낮은 높이
        max_area = std::max(min_height * (j - i + 1), max_area);    //최댓값과 비교하여 더 크면 바꿈
    }
    //세 가지 경우 중 최댓값 리턴
    return std::max(max_area, std::max(rectangle(left, mid), rectangle(mid + 1, right)));
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int C;
    std::cin >> C;
    while (C--)
    {
        int N;
        std::cin >> N;
        for (int i = 0; i < N; ++i) std::cin >> arr[i];
        std::cout << rectangle(0, N - 1) << '\n';
    }
}