#include <iostream>
using namespace std;

int visited[100][100];
int maze[100][100];
int N, M;

int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};

int min_value = 10000; //min���� �̸����� ����.. �������

// x�� ����, y�� ����
void DFS(int x, int y, int count)
{

    // 1. ��ǥ�� �����߳�?
    if (x == N - 1 && y == M - 1)
    {
        if(count < min_value){
            min_value = count;
        }
        return;
    }

    // 2. ����� ���� ��ȸ
    for (int i = 0; i < 4; i++)
    {
        if (0 <= x + x_dir[i] && x + x_dir[i] < N &&
            0 <= y + y_dir[i] && y + y_dir[i] < M){
                //3. ����Ǿ���, ������ �� �� �ִ°�?
                if(maze[x + x_dir[i]][y + y_dir[i]]==1 && !visited[x + x_dir[i]][y + y_dir[i]]){
                    //4.üũ��
                    visited[x + x_dir[i]][y + y_dir[i]] = true;

                    //5. �� �� �ִٸ� ����
                    DFS(x + x_dir[i], y + y_dir[i], count+1);

                    //6.üũ�ƿ�
                    visited[x + x_dir[i]][y + y_dir[i]] = false;
                }
            }
    }
}

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
    DFS(0, 0, 1); //����ĭ�� ����

    cout << min_value;
    return 0;
}