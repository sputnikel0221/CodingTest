#include <iostream>
#include <queue>
using namespace std;

int visited[100][100];
int maze[100][100];
int dist[100][100]; // �� ĭ������ �ּҰŸ��� �������

int N, M;

int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};

int min_value = 10000; // min���� �̸����� ����.. �������

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //*���� �Է¹ޱ�
    // N�� ����, M�� ����
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string s_tmp;
        cin >> s_tmp;

        for (int j = 0; j < M; j++)
        {
            maze[i][j] = s_tmp[j] - '0';
        }
    }

    //*�����
    // cout << "\n�迭 �Է°� ���\n";
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << maze[i][j];
    //     }
    //     cout << '\n';
    // }

    //* ����
    queue<pair<int, int>> path;
    path.push({0, 0});
    visited[0][0] = true;
    dist[0][0] = 1;

    //*BFS
    while (!path.empty())
    {
        // 1. Queue���� ������
        int x = path.front().first;
        int y = path.front().second;
        path.pop();

        // 2. ����� ���� ��ȸ
        for (int i = 0; i < 4; i++)
        {
            if (0 <= x + x_dir[i] && x + x_dir[i] < N &&
                0 <= y + y_dir[i] && y + y_dir[i] < M)
            {
                // 3. ����Ǿ���, ������ �� �� �ִ°�?
                if (maze[x + x_dir[i]][y + y_dir[i]] == 1 && !visited[x + x_dir[i]][y + y_dir[i]])
                {
                    // 4.üũ��
                    visited[x + x_dir[i]][y + y_dir[i]] = true;
                    // 5. Queue���� ����
                    path.push(make_pair(x + x_dir[i], y + y_dir[i]));
                    dist[x + x_dir[i]][y + y_dir[i]] = dist[x][y] + 1;
                }
            }
        }
    }
    cout << dist[N-1][M-1];
}