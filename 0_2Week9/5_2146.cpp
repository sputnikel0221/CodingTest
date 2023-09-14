#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int N;
int result = 987654321;

int map[101][101];
int t_map[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool visited[101][101];
bool t_visited[100][100];

// 1 Segfault - 섬의 개수는 매우 많을 수 있다
queue<pair<pair<int, int>, int>> coast[100000]; 


int count = 1; // 섬의 인덱스
void DFS(int x, int y)
{
    map[x][y] = count; // 섬의 인덱스를 붙임

    for (int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];

        if (cx < 0 || cx >= N || cy < 0 || cy >= N)
        {
            continue;
        }

        // 상하좌우에 0이 존재하면, coast큐에 원점을 넣는다.
        // 중복이 들어갈 수 있지만, 그냥 하는 것보단 시간 단축될 듯..
        if (map[cx][cy] == 0)
        {
            coast[count].push({{x, y}, 0});
        }

        if (map[cx][cy] == 1 && !visited[cx][cy])
        {
            visited[cx][cy] = 1;
            DFS(cx, cy);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    // 1 입력 그대로 받기
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    // 2 입력을 DFS를 통해 섬의 인덱스를 붙여서 Map을 수정
    // 2-1. DFS를 통해 섬 마다 해얀가의 위치를 시작점으로서 큐에 담음.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 1 && !visited[i][j])
            {
                visited[i][j] = 1;
                DFS(i, j);
                count++;
            }
        }
    }

    // 3 각 섬의 시작점으로부터 다른 섬에 방문시 length를 수정하는 BFS
    for (int c = 1; c < count; c++)
    {
        // visited를 t_visited로 복사 (memcpy를 사용했더니 while문이 동작하지 않음 왜?)
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                t_visited[i][j] = visited[i][j];
            }
        }

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                t_map[i][j] = map[i][j];
            }
        }

        while (!coast[c].empty())
        {
            int x = coast[c].front().first.first;
            int y = coast[c].front().first.second;
            int length = coast[c].front().second;
            coast[c].pop();

            for (int i = 0; i < 4; i++)
            {
                int cx = x + dx[i];
                int cy = y + dy[i];
                
                if (cx < 0 || cx >= N || cy < 0 || cy >= N)
                {
                    continue;
                }

                if (c != t_map[cx][cy] && t_map[cx][cy] > 0)
                {
                    result = min(result, length);
                    //cout << "\n"<< c << " -> " << t_map[cx][cy] << "\n" << cx << " : " << cy << " = " << length;
                }

                if (t_map[cx][cy] == 0 && !t_visited[cx][cy])
                {
                    t_visited[cx][cy] = 1;
                    t_map[cx][cy] = -1;

                    coast[c].push({{cx, cy}, length + 1});
                }
            }
        }
        
    }
    cout << result;
}
