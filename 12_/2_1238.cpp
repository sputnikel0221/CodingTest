#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int N, E, X;
vector<pair<int, int>> connection[1001]; // 1~1000 N
int d[1001];

priority_queue<int> goback;

int Dijkstra(int, int);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E >> X;

    while (E--)
    {
        int from, to, w;
        cin >> from >> to >> w;
        connection[from].push_back({w, to});
    }

    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        sum += Dijkstra(i, X);
        // cout << "1st " << i << " : " << sum << "\n";
        sum += Dijkstra(X, i);
        // cout << "2nd " << i << " : " << sum << "\n";
        goback.push(sum);
    }

    cout << goback.top();
    return 0;
}

int Dijkstra(int start, int end)
{
    if (start == end)
    {
        return 0;
    }

    fill(d, d + N + 1, INF);
    d[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({d[start], start});

    while (!pq.empty())
    {
        int cur_Dist = pq.top().first;
        int cur_Idx = pq.top().second;

        pq.pop();

        if (d[cur_Idx] != cur_Dist)
        {
            continue;
        }

        for (auto next : connection[cur_Idx])
        {
            int next_W = next.first;
            int next_Idx = next.second;

            if (d[next_Idx] <= cur_Dist + next_W)
            {
                continue;
            }
            else
            {
                d[next_Idx] = cur_Dist + next_W;
                pq.push({d[next_Idx], next_Idx});
            }
        }
    }
    return d[end];
}