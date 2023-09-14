#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int S, E;
bool map[100001];
int dx[3] = {1, -1, 0};  // dx[2]는 x2를 의미하려고 의미없는 0을 넣어둠

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> E;

    memset(map, 0, sizeof(map));
    priority_queue<pair<int, int>> q;   // 시간, 좌표
    q.push({0, S});
    map[S] = 1;

    while(!q.empty())
    {
        int count = -1 * q.top().first; // priority_queue의 우선순위 때문에
                                        // -1을 곱한 값을 queue에 넣게 됨.
        int x = q.top().second;        
        q.pop();

        if(x==E)
        {
            cout << count;
            return 0;
        }

        map[x] = 1; // 왜 여기서 visited를 체크 해야만 통과가 되는거지??
        
        for(int i=0;i<3;i++)
        {
            int cx = x + dx[i];

            if(i==2)    // x2라면,
            {
                cx = x * 2;
            }   

            if(cx < 0 || cx > 100000)
            {
                continue;
            }
            
            if(!map[cx])
            {
                //map[cx] = 1;  // ==원래의 위치==

                if(i==2) // x2라면,
                {
                    q.push({-count, cx});
                }
                else
                {
                    q.push({-(count+1), cx});
                }
            }
        }
    }
    return 0;   
}