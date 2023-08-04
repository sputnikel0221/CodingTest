#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int map[1000][1000];
int wall = 0;
int maxDay = 0;

queue<pair<int, int>> nextNode;

int dx[4] = {0, -1, 0, 1}; // 위왼아오
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N; // M이 가로, N이 세로 (2~1000)
    memset(map, 0, sizeof(map));

    // map 생성 및 익은토마토 큐에 추가
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                nextNode.push(make_pair(j, i));
                //cout << " tomato  x:" << i << " y" << j;
            }
            else if (map[i][j] == -1)
            {
                wall++;
            }
        }
    }

    // 익은 토마토의 개수와 모든 토마토의 개수(전체칸에서 wall만 뺀 토마토의 개수)
    // 가 같다면, 모든 토마토가 익어있는 상태라서 0 출력
    if (nextNode.size() == (N * M - wall))
    {
        cout << 0;
        return 0;
    }

    // BFS
    while (!nextNode.empty())
    {
        int x = nextNode.front().first;
        int y = nextNode.front().second;
        nextNode.pop();

        for (int i = 0; i < 4; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];

            if(cx < 0 || cx >= M || cy < 0 || cy >= N)
            {
                continue;
            }
            else
            {
                if(map[cy][cx] == 0)
                {
                    map[cy][cx] = map[y][x] + 1;    //이전날짜의 값+1을 부여
                    maxDay = map[cy][cx];
                    nextNode.push(make_pair(cx, cy));
                }
            }
        }
    }

    // 다 하고서도 익지 않은 토마토가 있다면, -1을 출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << maxDay -1; //시간이므로 -1일

    return 0;
}