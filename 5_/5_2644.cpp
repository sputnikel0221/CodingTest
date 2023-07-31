#include <iostream>
#include <queue>
// #include <stack>

#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    int ans_From;
    int ans_To;
    cin >> ans_From;
    cin >> ans_To;

    bool connection[N + 1][N + 1]; // 적용 안됨
    bool visited[N + 1];           // 2차원배열인 간선이 아닌, 1차원 배열로 정점을 기준으로 하였다.
                                   // 중복된 정점을 통과하지 못하도록 한다.
    memset(connection, false, sizeof(connection));
    memset(visited, false, sizeof(visited));

    int T;
    cin >> T;

    int from, to;
    for (int i = 0; i < T; i++)
    {
        cin >> from;
        cin >> to;

        connection[from][to] = true;
        connection[to][from] = true;
    }

    queue<int> nextNode;
    nextNode.push(ans_From);

    int path[N + 1] = {
        0,
    };
    
    while (!nextNode.empty())
    {
        int num = nextNode.front();
        nextNode.pop();

        if (num == ans_To)
        {
            break;
        }

        for (int i = 1; i < N + 1; i++)
        {
            if (connection[num][i] && !visited[i])
            {
                visited[num] = true;
                path[i] = num;

                nextNode.push(i);
            }
        }
    }

    //도달하지 못한 경우
    if(path[ans_To]==0)
    {
        cout << -1 << "\n";
        return 0;
    }

    // 역추적

    int i = path[ans_To];
    int count = 0;
    while (true)
    {
        count++;
        if (i != ans_From)
        {
            i = path[i];
        }
        else
        {
            break;
        }
    }

    cout << count <<"\n";
    return 0;
}