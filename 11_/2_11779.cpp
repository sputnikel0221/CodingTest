#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <stack>

using namespace std;


const int INF = numeric_limits<int>::max();

int n_city, n_road;
int startIndex, endIndex;

vector<pair<int, int>> connection[1001];
int d[1001] = {0,};

int track[1001] = {0, };

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n_city;
    cin >> n_road;

    // INF로 채우기
    fill(d, d+1001+1, INF);

    // 입력
    while(n_road--)
    {
        int a, b, w;
        cin >> a >> b >> w;

        connection[a].push_back({w, b});
    }
    cin >> startIndex >> endIndex;

    // 반례 : 입력과 출력이 같은 경우 
    if(startIndex == endIndex)
    {
        cout << 0 << "\n";
        cout << 1 << "\n";
        cout << startIndex;
        return 0;
    }

    // 큐 생성 및 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[startIndex] = 0;
    pq.push({d[startIndex], startIndex});

    while(!pq.empty())
    {
        int cur_Dist = pq.top().first;
        int cur_Index = pq.top().second;

        pq.pop();

        if(d[cur_Index] != cur_Dist)
        {
            continue;
        }

        for(auto next : connection[cur_Index])
        {
            int next_Weight = next.first;
            int next_Index = next.second;

            if(d[next_Index] <= d[cur_Index] + next_Weight)
            {
                continue;
            }
            else    //갱신
            {
                track[next_Index] = cur_Index;  // track에 기록
                d[next_Index] = d[cur_Index] + next_Weight;
                pq.push({d[next_Index], next_Index});
            }
        }
    }

    // 출력
    cout << d[endIndex] << "\n";
    
    stack<int> trackPrint;
    trackPrint.push(endIndex);

    int count = 0;
    int index = endIndex;
    while(true)
    {
        if(track[index] != startIndex)
        {
            count++;
            index = track[index];
            trackPrint.push(index);
        }
        else
        {
            break;
        }
    }
    trackPrint.push(startIndex);
    
    cout << count+2 << "\n";
    
    while(!trackPrint.empty())
    {
        cout << trackPrint.top() << " ";
        trackPrint.pop();
    }

    return 0;   
}