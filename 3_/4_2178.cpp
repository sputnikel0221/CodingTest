#include <iostream>
using namespace std;

int visited[100][100];
int maze[100][100];
int N, M;

int x_dir[4] = {-1, 1, 0, 0};
int y_dir[4] = {0, 0, -1, 1};

int min_value = 10000; //min으로 이름짓지 말것.. 예약어임

// x는 세로, y는 가로
void DFS(int x, int y, int count)
{

    // 1. 목표에 도달했나?
    if (x == N - 1 && y == M - 1)
    {
        if(count < min_value){
            min_value = count;
        }
        return;
    }

    // 2. 연결된 곳을 순회
    for (int i = 0; i < 4; i++)
    {
        if (0 <= x + x_dir[i] && x + x_dir[i] < N &&
            0 <= y + y_dir[i] && y + y_dir[i] < M){
                //3. 연결되었고, 실제로 갈 수 있는가?
                if(maze[x + x_dir[i]][y + y_dir[i]]==1 && !visited[x + x_dir[i]][y + y_dir[i]]){
                    //4.체크인
                    visited[x + x_dir[i]][y + y_dir[i]] = true;

                    //5. 갈 수 있다면 간다
                    DFS(x + x_dir[i], y + y_dir[i], count+1);

                    //6.체크아웃
                    visited[x + x_dir[i]][y + y_dir[i]] = false;
                }
            }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //*값들 입력받기
    // N이 세로, M이 가로
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

    //*디버그
    // cout << "\n배열 입력값 출력\n";
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         cout << maze[i][j];
    //     }
    //     cout << '\n';
    // }

    //* 시작
    DFS(0, 0, 1); //시작칸도 포함

    cout << min_value;
    return 0;
}