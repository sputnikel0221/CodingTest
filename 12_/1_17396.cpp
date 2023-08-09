#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, E;
    cin >> N >> E;

    bool cantGo[100001];
    for(int i=0; i<N; i++)
    {
        cin >> cantGo[i];
    }
    cantGo[N-1] = false;

    vector<pair<long long, long long>> connection[100001];

    while(E--)
    {
        long long a, b, w;
        cin >> a >> b >> w;

        // 양방향
        connection[a].push_back({w, b});
        connection[b].push_back({w, a});
    }

    const long long INF = numeric_limits<long long>::max();
    long long d[N];
    fill(d, d+N+1,INF);

    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
    d[0] = 0;
    pq.push({d[0], 0});

    while(!pq.empty())
    {
        long long cur_Dist = pq.top().first;
        long long cur_Idx = pq.top().second;

        pq.pop();


        if(d[cur_Idx] < cur_Dist){
            continue;
        }

        for(auto next : connection[cur_Idx])
        {
            long long next_W = next.first;
            long long next_Idx = next.second;

            // 해당 조건이 문제 핵심
            if(cantGo[next_Idx])
            {
                //cout << "cant Go :" << next_Idx << "\n";
                continue;
            }

            if(d[next_Idx] <= next_W + d[cur_Idx])
            {
                continue;
            } 
            else
            {
                d[next_Idx] = next_W + d[cur_Idx];
                pq.push({d[next_Idx], next_Idx});
            }
        }
    }

    if(d[N-1] == INF)
    {
        cout << -1;
        return 0;
    }
    cout << d[N-1];

    return 0;   
}