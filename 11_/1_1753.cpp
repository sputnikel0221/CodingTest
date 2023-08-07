#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#include <cstring>

using namespace std;

int v, e;
int start_v;

// int형의 최대값을 INF로 저장
const int INF = numeric_limits<int>::max();

int d[20001] = {
    0,
};
vector<pair<int, int>> connection[20001];   // 가중치, 연결된 정점

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    cin >> start_v;

    fill(d, d + v + 1, INF); // 배열을 d[0]~d[v]까지 INF로 채움

    // 그래프 입력
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w; // u와 v가 연결된 선의 가중치는 w

        connection[u].push_back({w, v}); // w부터 저장하는 법 통일
    }

    // vector<pair<int, int> 구조에 pair<int, int> 자료형을 넣음 pair<int, int>를 오름차순
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 시작점 추가
    d[start_v] = 0;
    pq.push({d[start_v], start_v}); // 해당 점까지의 최단거리, (갈수있는 점)

    while (!pq.empty())
    {
        // 1
        auto cur = pq.top(); // pair<int, int>, pq의 가장 첫번째(*거리가 가장작은값)를 가져온다
        pq.pop();

        // 2
        if (d[cur.second] != cur.first) // 현재 점까지의 최단거리가, 넣어진 거리와 다르다면, (d는 항상 최단거리만 저장한다)
        {
            continue; // 해당 경로를 더 갱신할 필요가 없으므로, 그냥 무시하고 queue를 다시 뽑음
        }

        // 3
        for (auto nxt : connection[cur.second]) // 현재 점에 대한 연결들을 순회 // 가중치, 연결된 정점이 반환됨
        {
            if (d[nxt.second] <= d[cur.second] + nxt.first) // 현재 점을 통해 연결된 다음 점을 방문할때, d보다 크다면 갱신안함
            {
                continue;
            }
            else                                            // 그렇지 않다면, 갱신함.
            {
                d[nxt.second] = d[cur.second] + nxt.first; 
                pq.push({d[nxt.second], nxt.second});
            }
        }
    }

    // 출력
    for (int i = 1; i <= v; i++)
    {
        if (d[i] == INF)
        {
            cout << "INF\n";
        }
        else
        {
            cout << d[i] << "\n";
        }
    }

    return 0;
}