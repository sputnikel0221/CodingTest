#include <iostream>
#include <cstring>
using namespace std;

int N, M;
bool connection[2001][2001];
bool visited[2001];

int flag = 0;

void DFS(int num, int count)
{
    if (count == 4)
    {
        flag = 1;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (connection[num][i] && !visited[i])
        {
            visited[i] = true;
            DFS(i, count + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;

        connection[from][to] = 1;
        connection[to][from] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (flag)
            {
                cout << flag;
                return 0;
            }
            if (connection[i][j])
            {

                memset(visited, 0, sizeof(visited));
                visited[i] = visited[j] = true;

                DFS(j, 1);
            }
        }
    }
    cout << flag;

    return 0;
}