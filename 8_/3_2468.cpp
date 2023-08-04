#include <iostream>
#include <cstring>

using namespace std;

int N;
int map[100][100];
bool visited[100][100];
void DFS(int, int);
int height = 0;
int maxIsland = 1; // 0이면 height를 다 할 필요가 없음 // 0의 높이로 잠기게 한 값 //최대섬
int thisIsland;    // 현재 개수

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    memset(map, 0, sizeof(map));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[j][i];
        }
    }

    // 최대 높이가 100이기때문에 100을 포함할 필요가 없다.
    for (int t = 1; t < 100; t++)
    {
        memset(visited, false, sizeof(visited));

        thisIsland = 0;
        height = t;     // t 높이 까지의 지역을 잠기게 함

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // 해당 높이 이상이고, 방문하지 않았다면 해당 점을 기준으로 DFS진행
                if (map[j][i] > t && !visited[j][i])
                {
                    visited[j][i] = 1;
                    DFS(i, j);
                    thisIsland++;
                }
            }
        }
        // thisIsland가 0이면 다음 물높이에서도 모두 잠길것이므로 바로 break;
        if(thisIsland == 0)
        {
            break;
        }

        if(maxIsland < thisIsland)
        {
            maxIsland = thisIsland;
        }
    }
    cout << maxIsland;

    return 0;
}

void DFS(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];

        if (cx < 0 || cy < 0 || cx >= N || cy >= N)
        {
            continue;
        }
        // 해당 점을 기준으로 갈 수 있는 곳이라면,
        else
        {
            // 갈 수 있고 방문하지 않은 곳이라면,
            if (!visited[cy][cx] && map[cy][cx] > height)
            {
                visited[cy][cx] = 1;
                DFS(cx, cy);
            }
        }
    }
}