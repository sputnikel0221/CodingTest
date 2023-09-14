#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int s_x, s_y;
int e_x, e_y;

bool map[301][301];
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {-1,-2,-2,-1,1,2,2,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
        //cout << "T : "<< T <<"\n";
        cin >> N;
        cin >> s_x >> s_y;
        cin >> e_x >> e_y;

        memset(map, 0, sizeof(map));
        queue<pair<pair<int, int>, int>> q;
        q.push({{s_x, s_y}, 0});

        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int count = q.front().second;

            q.pop();

            if(x==e_x && y==e_y)
            {
                cout << count << "\n";
                break;
            }

            for(int i=0;i<8;i++)
            {
                int cx = x + dx[i];
                int cy = y + dy[i];

                if(cx < 0 || cx >= N || cy<0 || cy>=N)
                {
                    continue;
                }

                if(!map[cx][cy])
                {
                    map[cx][cy] = 1;
                    q.push({{cx, cy}, count+1});
                }
            }
        }
    }


    return 0;   
}