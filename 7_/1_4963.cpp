#include <iostream>
#include <cstring>

using namespace std;

int dirX[8]{-1, -1, -1, 0, 1, 1, 1, 0};
int dirY[8]{1, 0, -1, -1, -1, 0, 1, 1};

void DFS(int, int);
bool map[51][51]; // int는 너무 커서 bool로 생성
int w, h;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count;

    while (true)
    {
        count = 0;
        cin >> w >> h;

        if (!w && !h)
        {
            break;
        }

        // 맵 초기화
        memset(map, 0, sizeof(map));

        // 맵 저장
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> map[i][j];
            }
        }

        // 계산
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (map[i][j] == 1)
                {
                    count++;
                    DFS(j, i);
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}

void DFS(int x, int y)
{

    if (map[y][x] == 0)
    {
        return;
    }

    // 현재 x,y좌표값을 0으로 만듦
    map[y][x] = 0;

    
    for (int i = 0; i < 8; i++)
    {
        if ((0 <= x + dirX[i]) && (x + dirX[i] < w) && (0 <= y + dirY[i]) && (y + dirY[i] < h))
        {
            if (map[y + dirY[i]][x + dirX[i]] == 1)
            {
                DFS(x + dirX[i], y + dirY[i]);
            }
        }
    }

}