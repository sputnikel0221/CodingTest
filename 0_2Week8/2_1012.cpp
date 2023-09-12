#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T, K;
int N, M;

bool map[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int worm = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
        // 가로, 세로, 배추개수
        cin >> M >> N >> K;
        
        // 초기화
        worm = 0;
        memset(map, 0, sizeof(map));
        queue<pair<int, int>> q;

        // 배추심기
        while(K--)
        {
            int x, y;
            cin >> y >> x;
            map[x][y] = 1;
        }

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(!map[i][j])
                {
                    continue;
                }

                if(map[i][j])
                {
                    worm++;
                    q.push({i, j});
                    map[i][j] = 0;
                }

                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;

                    q.pop();

                    for(int k=0;k<4;k++)
                    {
                        int cx = x + dx[k];
                        int cy = y + dy[k];

                        if(cx < 0 || cx >= N || cy < 0 || cy >= M)
                        {
                            continue;
                        }
                        else
                        {
                            if(map[cx][cy])
                            {
                                map[cx][cy] = 0;
                                q.push({cx, cy});
                            }
                        }
                    }
                }
            }
        }
        cout << worm << "\n";
    }

    return 0;   
}