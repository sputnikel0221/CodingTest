#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
bool visited[1000][1000][2]; // 마지막은 벽을 부시는 능력을 썼는지
int map[1000][1000];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int map_X, map_Y;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> map_X >> map_Y;
    memset(visited, false, sizeof(visited));
    memset(map, 0, sizeof(map));

    string s;
    for (int i = 0; i < map_X; i++)
    {
        cin >> s;
        for (int j = 0; j < map_Y; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }

    queue<pair<pair<int, int>, pair<int, int>>> nextNode;
    visited[0][0][1] = true;
    nextNode.push({{0, 0}, {1, 1}});

    while (!nextNode.empty())
    {
        int x = nextNode.front().first.first;
        int y = nextNode.front().first.second;
        int count = nextNode.front().second.first;
        int remainAbility = nextNode.front().second.second;

        nextNode.pop();

        /*
        cout << "\n\n[thisNode]\n";
        cout << "x : " << x << "\n";
        cout << "y : " << y << "\n";
        cout << "count : " << count << "\n";
        cout << "remain : " << remainAbility << "\n";
        */

        if (x == map_X - 1 && y == map_Y - 1)
        {
            cout << count;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int cx = x + dx[i];
            int cy = y + dy[i];

            if (cx < 0 || cx >= map_X || cy < 0 || cy >= map_Y)
            {
                continue;
            }
            else
            {
                if (map[cx][cy] == 0)
                {
                    if (!visited[cx][cy][remainAbility])
                    {
                        visited[cx][cy][remainAbility] = true;
                        nextNode.push({{cx, cy}, {count + 1, remainAbility}});
                    }
                }
                else if (map[cx][cy] == 1)
                {
                    if (remainAbility > 0)
                    {
                        visited[cx][cy][remainAbility - 1] = true;
                        nextNode.push({{cx, cy}, {count + 1, remainAbility - 1}});
                    }
                }
            }
        }
    }
    cout << -1;
    return 0;
}