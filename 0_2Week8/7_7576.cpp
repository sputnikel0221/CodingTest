#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<int> map[1001];
int result=0;
int min_day[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // N이 세로 / M이 가로
    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int n;
            cin >> n;
            map[i].push_back(n);

            //min_day[i][j] = 9999;
        }
    }

    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1)
            {
                map[i][j] = 1;
                q.push({{i, j}, 0});

                while (!q.empty())
                {
                    int x = q.front().first.first;
                    int y = q.front().first.second;
                    int day = q.front().second;

                    //min_day[x][y] = min(min_day[x][y], day);

                    result = day;
                    q.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        int cx = x + dx[i];
                        int cy = y + dy[i];

                        if (cx < 0 || cx >= N || cy < 0 || cy >= M)
                        {
                            continue;
                        }

                        if(map[cx][cy]==0)
                        {
                            map[cx][cy] = 1; // 중요 : queue에 넣기전 visited
                            q.push({{cx,cy}, day+1});
                            cout << cx << " : " << cy << "=" << day+1 << "\n";
                        }
                    }
                }
            }
        }
    }
    
    bool toFlag = true;
    for(int i=0; i<N;i++)
    {
        for(auto k : map[i])
        {
            if(k==0)
            {
                toFlag=false;
            }
        }
    }

    for(int i=0; i<N;i++)
    {
        cout << "\n";
        for(auto k : map[i])
        {
            cout << k << " ";
        }
    }

    if(toFlag)
    {
        cout << result;
    }
    else
    {
        cout << -1;
    }    

    return 0;
}