#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> v[2001];    // 벡터를 써야만 한다.
bool visited[2001];

int flag = 0;

void DFS(int num, int count)
{
    if (count == 4)
    {
        flag = 1;
        return;
    }

    for (auto i : v[num])
    {
        if (!visited[i])
        {
            visited[i] = true;
            DFS(i, count + 1);
            visited[i] = false; // 백트래킹
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

        v[from].push_back(to);
        v[to].push_back(from);
    }

    // v[i]는 i번째 수에 연결된 원소들은 v[i][0]부터 차곡차곡 저장
    for (int i = 0; i < N; i++)
    {
        for (auto j : v[i])
        {
            if (flag)
            {
                cout << flag;
                return 0;
            }

            memset(visited, 0, sizeof(visited));
            visited[i] = visited[j] = true;

            DFS(j, 1);
        }
    }
    cout << flag;

    return 0;
}