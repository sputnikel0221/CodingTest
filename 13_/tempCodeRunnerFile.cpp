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

    // 3 본인
    for (int i = 1; i <= V; i++)
    {
        d[i][i] = 0;
    }

    // 4 FLO-WAR
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

    for (int i = 1; i <= V; i++)
    {
        cout << i << " : " << d[i][i] << "\n";
    }

    int minCycle = 10001;
    // 5 Cycle
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            if (d[i][j] + d[j][i] != 0)
            {
                minCycle = min(minCycle, d[i][j] + d[j][i]);
            }
        }
    }
    if (minCycle == 10001)
    {
        cout << -1;
        return 0;
    }

    cout << minCycle;

    return 0;
}