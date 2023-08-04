#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
bool alphabet[26] = {
    0,
};
string s[20] = {
    "",
};

int N, M;
int maxCount = 0;

void DFS(int, int, int);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M; // N이세로 M이가로

    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
    }

    // A아스키 = 65 / 총 26개의 알파벳
    alphabet[s[0][0] - 65] = 1;
    DFS(0, 0, 1);
    
    cout << maxCount;
    
    return 0;
}

void DFS(int x, int y, int count)
{
    bool exitFlag = false;

    for (int i = 0; i < 4; i++)
    {
        int cx = x + dx[i];
        int cy = y + dy[i];

        if (cx < 0 || cx >= M || cy < 0 || cy >= N)
        {
            continue;
        }
        else
        {
            // 방문하지 않았다면
            if (!alphabet[s[cy][cx]-65])
            {
                exitFlag = true;

                alphabet[s[cy][cx]-65] = 1;
                DFS(cx, cy, count+1);
                alphabet[s[cy][cx]-65] = 0;
            }
        }
    }
    // 더이상 갈곳이 없는 막다른길
    if(exitFlag==false)
    {
        if(maxCount < count)
        {
            maxCount = count;
        }
        return;
    }
}