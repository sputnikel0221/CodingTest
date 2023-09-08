#include <iostream>
#include <algorithm>

using namespace std;

char map[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void check_ud(int x, int y, char a, char b);
void check_lr(int x, int y, char a, char b);

void check();

int N;
int result = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = s[j];
        }
    }

    // 0 - 원래 배열에서 확인
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            check_ud(i, i + 1, map[i][j], map[i + 1][j]);
        }
    }

    // 0 - 원래 배열에서 확인
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            check_lr(j, j + 1, map[i][j], map[i][j + 1]);
        }
    }

    check();

    // 1 - 행 교환 : 아래랑 위아래 교환
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] != map[i + 1][j])
            {
                swap(map[i][j], map[i + 1][j]);
                //check_ud(i, i + 1, map[i][j], map[i + 1][j]);
                check();
                swap(map[i][j], map[i + 1][j]);
            }
        }
    }

    // 2 - 열 교환 : 오른쪽과 왼오 교환
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (map[i][j] != map[i][j + 1])
            {
                swap(map[i][j], map[i][j + 1]);
                //check_lr(j, j + 1, map[i][j], map[i][j + 1]);
                check();
                swap(map[i][j], map[i][j + 1]);
            }
        }
    }

    cout << result;

    return 0;
}

void check_ud(int x, int y, char a, char b)
{
    int a_max = 0, b_max = 0;

    // 1 x행에서 가로비교
    int ud_count = 0;
    for (int q = 0; q < N; q++)
    {
        if (map[x][q] == a)
        {
            ud_count++;

            if (ud_count > a_max)
            {
                a_max = ud_count;
            }
        }
        else
        {
            ud_count = 0;
        }
    }

    // 2 y행에서 가로비교
    ud_count = 0;
    for (int q = 0; q < N; q++)
    {
        if (map[y][q] == b)
        {
            ud_count++;

            if (ud_count > b_max)
            {
                b_max = ud_count;
            }
        }
        else
        {
            ud_count = 0;
        }
    }

    result = max(result, a_max);
    result = max(result, b_max);
}
void check_lr(int x, int y, char a, char b)
{
    int a_max = 0, b_max = 0;

    // 1 x열에서 세로비교
    int lr_count = 0;
    for (int q = 0; q < N; q++)
    {
        if (map[q][x] == a)
        {
            lr_count++;

            if (lr_count > a_max)
            {
                a_max = lr_count;
            }
        }
        else
        {
            lr_count = 0;
        }
    }

    // 2 y열에서 세로비교
    lr_count = 0;
    for (int q = 0; q < N; q++)
    {
        if (map[q][y] == b)
        {
            lr_count++;

            if (lr_count > b_max)
            {
                b_max = lr_count;
            }
        }
        else
        {
            lr_count = 0;
        }
    }

    result = max(result, a_max);
    result = max(result, b_max);
}

void check()
{
    char c;

    for(int i=0;i<N;i++)
    {
        int c_count = 1;
        c = map[i][0];

        for(int j=1;j<N;j++)
        {
            if(map[i][j] == c)
            {
                c_count++;
            }
            else
            {
                c_count = 1;
            }
            c = map[i][j];

            if(c_count > result)
            {
                result = c_count;
            }
        }
    }

    
    for(int i=0;i<N;i++)
    {
        int d_count = 1;
        c = map[0][i];

        for(int j=1;j<N;j++)
        {
            if(map[j][i] == c)
            {
                d_count++;
            }
            else
            {
                d_count = 1;
            }
            c = map[i][j];

            if(d_count > result)
            {
                result = d_count;
            }
        }
    }
}