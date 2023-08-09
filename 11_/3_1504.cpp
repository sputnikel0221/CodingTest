#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <limits>
#include <set>

using namespace std;

int N, E;
vector<pair<int, int>> connection[801];

const int INF = numeric_limits<int>::max();

int d[801] = {
    0,
};
int track[801] = {
    0,
}; // 역추적배열

int Dijkstra(int, int);

bool zeroFlag = false;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum1 = 0; // 1-v1-v2-N
    int sum2 = 0; // 1-v2-v1-N

    // 입력
    cin >> N >> E;
    while (E--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        connection[a].push_back({c, b});    //* 양방향 연결임을 간과했었다
        connection[b].push_back({c, a});
    }

    int v1, v2;
    cin >> v1 >> v2;

    // 순방향 1-v1-v2-N
    sum1 += Dijkstra(v1, v2);
    sum1 += Dijkstra(1, v1);
    sum1 += Dijkstra(v2, N);

    // 꼰방향 1-v2-v1-N
    sum2 += Dijkstra(v1, v2);
    sum2 += Dijkstra(1, v2);
    sum2 += Dijkstra(v1, N);

    // 예외처리
    if (zeroFlag == true)
    {
        cout << -1;
        return 0;
    }

    // 더 작은 경로값 출력
    if (sum1 <= sum2)
    {
        cout << sum1;
    }
    else
    {
        cout << sum2;
    }

    return 0;
}

int Dijkstra(int start, int end)
{
    if (start == end)
    {
        return 0;
    }

    // zeroFlag 넣으면 더 할필요 없으므로 시간단축
    if (zeroFlag == true)
    {
        cout << -1;
        return 0;
    }

    fill(d, d + N + 1, INF);    //* memset이 아니라 fill을 사용해야만 했다.

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[start] = 0;
    pq.push({d[start], start});

    while (!pq.empty())
    {
        int cur_Dist = pq.top().first;
        int cur_Index = pq.top().second;

        pq.pop();

        if (d[cur_Index] != cur_Dist)
        {
            continue;
        }

        for (auto next : connection[cur_Index])
        {
            int next_Weight = next.first;
            int next_Index = next.second;

            if (d[next_Index] <= cur_Dist + next_Weight)
            {
                continue;
            }
            else
            {
                d[next_Index] = cur_Dist + next_Weight;
                pq.push({d[next_Index], next_Index});
            }
        }
    }
    //cout << "start : " << start << " /end : " << end << " /dist : " << d[end] << "\n";

    // 도착점까지 거리가 INF라는것은, 한번도 방문하지 못했기 떄문
    if (d[end] == INF)
    {
        zeroFlag = true;
    }

    return d[end];
}
