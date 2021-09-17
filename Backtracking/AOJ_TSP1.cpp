#include <iostream>
#include <iomanip>
double TSP(double** DM, int N, int city = 0, double distance = 0)
{
    double min = 1415 * 10;
    DM[city][city] = 1416;    //방문했음을 표시
    bool finish = true;
    for (int i = 0; i < N; ++i) if (DM[i][i] == 0)  //도시 i에 방문한 적이 없으면
    {
        finish = false; //모두 방문한것은 아니므로 false
        double ret = TSP(DM, N, i, distance + DM[city][i]); //도시 i방문, 거리 추가
        if (min > ret) min = ret;
    }
    DM[city][city] = 0;
    if (finish) return distance;    //모든 도시에 방문했으면 거리 return
    return min;
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

        double** distance_matrix = new double* [N];
        for (int i = 0; i < N; ++i)
        {
            distance_matrix[i] = new double[N];
            for (int j = 0; j < N; ++j) std::cin >> distance_matrix[i][j];
        }

        double min = 1415 * 10;
        for (int i = 0; i < N; ++i) //처음 출발한 도시로 돌아오지 않기 때문에 각 도시에서 출발하는경우를 모두 계산해야 함
        {
            double ret = TSP(distance_matrix, N, i);
            if (min > ret) min = ret;
        }
        std::cout << std::fixed << std::setprecision(10) << min << '\n';
    }
}