#include <iostream>
int TSP(int** DM, int N, int city = 0, int distance = 0)
{
    int min = 1'000'000 * 10;
    DM[city][city] = 987654321;    //방문했음을 표시
    bool finish = true;
    for (int i = 0; i < N; ++i) if (DM[i][i] == 0)  //도시 i에 방문한적이 없으면
    {
        finish = false; //모두 방문한것은 아니므로 false
        if (DM[city][i] != 0)   //city에서 i로 가는 경로가 있으면
        {
            int ret = TSP(DM, N, i, distance + DM[city][i]);    //도시 i방문, 비용(거리) 추가
            if (min > ret) min = ret;
        }
    }
    DM[city][city] = 0;
    //모든 도시를 방문했고, city -> 0 (처음 출발한 도시)으로 가는 길이 있으면 최종 거리를 return
    if (finish && DM[city][0] != 0) return distance + DM[city][0];
    return min;
}
int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N;
    std::cin >> N;

    int** distance_matrix = new int* [N];
    for (int i = 0; i < N; ++i)
    {
        distance_matrix[i] = new int[N];
        for (int j = 0; j < N; ++j) std::cin >> distance_matrix[i][j];
    }

    std::cout << TSP(distance_matrix, N);  
}