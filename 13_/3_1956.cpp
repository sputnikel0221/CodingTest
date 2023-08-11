#include <iostream>
using namespace std;

int V, E;
int d[401][401];
const int INF = 100000000;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;

    // 1 INF
    for (int i = 1; i <= V; i++)
    {
        fill(d[i], d[i] + V + 1, INF);
    }

    // 2 입력
    while (E--)
    {
        int from, to, w;
        cin >> from >> to >> w;
        d[from][to] = w;
    }

    // 3 FLO-WAR
    for (int k = 1; k <= V; k++)
    {
        for (int i = 1; i <= V; i++)
        {
            for (int j = 1; j <= V; j++)
            {
                if (d[i][j] <= d[i][k] + d[k][j])
                {
                    continue;
                }
                else
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    // 4 Cycle 존재유무 판별
    bool isCycle = false;
    for (int i = 1; i <= V; i++)
    {
        if (d[i][i] < INF)
        {
            isCycle = true;
        }
    }
    if (!isCycle)   // 사이클이 없다면
    {
        cout << -1;
        return 0;
    }

    // 5 Cycle 최소값 판별
    int minCycle = 4000000;
    for (int i = 1; i <= V; i++)
    {
        minCycle = min(minCycle, d[i][i]);
    }

    cout << minCycle;

    return 0;
}