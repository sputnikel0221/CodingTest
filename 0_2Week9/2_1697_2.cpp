#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int S, E;
bool map[100001];
int dx[3] = {1,-1,0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> E;

    memset(map, 0, sizeof(map));
    queue<pair<int, int>> q;
    q.push({S, 0});

    while(!q.empty())
    {
        int x = q.front().first;
        int count = q.front().second;

        q.pop();

        if(x==E)
        {
            cout << count;
            return 0;
        }

        for(int i=0;i<3;i++)
        {
            int cx = x + dx[i];

            if(i==2)
            {
                cx = x * 2;
            }   

            if(cx < 0 || cx > 100000)
            {
                continue;
            }

            if(!map[cx])
            {
                map[cx] = 1;
                q.push({cx, count+1});
            }
        }
    }
    return 0;   
}