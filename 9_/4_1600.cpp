#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int K, map_x, map_y;
int dx[12] = {-1, -2, -2, -1, 1, 2, 2, 1, 0, -1, 0, 1}; // 실제론 y값
int dy[12] = {2, 1, -1, -2, -2, -1, 1, 2, 1, 0, -1, 0};
bool visit[200][200][31];
int map[200][200];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(visit, false, sizeof(visit));
    memset(map, 0, sizeof(map));

    cin >> K;
    cin >> map_y >> map_x; // 가로와 세로 순으로 입력을 받지만, 변수명은 다르게 한다.

    for (int i = 0; i < map_x; i++) // 사실상 세로 가로로 저장이지만, 변수명이 x,y
    {
        for (int j = 0; j < map_y; j++)
        {
            cin >> map[i][j];

            // 벽을 왜 방문표시 하는거지?
            if (map[i][j] == 1)
            {
                visit[i][j][K] = true;
            }
        }
    }

    visit[0][0][K] = true;
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {0, K}}); // make_pair을 굳이 사용하지 않아도 됨

    while (!q.empty())
    {
        int this_x = q.front().first.first;
        int this_y = q.front().first.second;

        int moveCount = q.front().second.first;
        int horseRemain = q.front().second.second;

        q.pop();

        /*
        cout << "*******************\n";
        cout << "X " << this_x << "!\n";
        cout << "Y " << this_y << "!\n";
        cout << "moveCount = " << moveCount << "!\n";
        cout << "horseRemain = " << horseRemain << "!\n";
        */
       
        // 목표에 도달 - 종료조건
        if (this_x == map_x - 1 && this_y == map_y - 1)
        {
            cout << moveCount;
            return 0;
        }

        // 상하좌우
        for (int i = 8; i < 12; i++)
        {
            int cx = this_x + dx[i];
            int cy = this_y + dy[i];

            if (cx < 0 || cx >= map_x || cy < 0 || cy >= map_y)
            {
                continue;
            }
            else
            {
                if (!map[cx][cy] && visit[cx][cy][horseRemain] == false)
                {
                    visit[cx][cy][horseRemain] = true;
                    q.push({{cx, cy}, {moveCount + 1, horseRemain}});
                }
            }
        }

        // horseRemain이 없다면 굳이 아래의 코드들은 실행할 필요가 없으므로
        if (horseRemain == 0)
        {
            continue;
        }

        // 말 이동 8방향
        for (int i = 0; i < 8; i++)
        {
            int cx = this_x + dx[i];
            int cy = this_y + dy[i];

            if (cx < 0 || cx >= map_x || cy < 0 || cy >= map_y)
            {
                continue;
            }
            else
            {
                // horseReamin을 하나 사용한 곳을 추가할지 결정
                if (!map[cx][cy] && visit[cx][cy][horseRemain - 1] == false)
                {
                    visit[cx][cy][horseRemain - 1] = true;
                    q.push({{cx, cy}, {moveCount + 1, horseRemain - 1}});
                }
            }
        }
    }

    //cout << "while out";


    cout << -1;

    return 0;
}