#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, Start;
bool Connection[1001][1001]; // DFS때문에 밖에 세팅
bool Visited[1001] = {
    false,
};
int DFSPath[1001] = {
    0,
};

int DFScount = 1;
void DFS(int);
void BFS(int);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(Connection, false, sizeof(Connection));

    cin >> N >> M >> Start;

    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        Connection[from][to] = true;
        Connection[to][from] = true;
    }

    cout << Start << " ";
    DFS(Start);

    BFS(Start);

    return 0;
}

void DFS(int num)
{
    DFScount++;

    Visited[num] = true;

    for (int i = 1; i < N + 1; i++)
    {
        if (Connection[num][i] && !Visited[i])
        {
            Visited[i] = true;
            cout << i << " ";
            if (DFScount == N)
            {
                return;
            }
            DFS(i);
            Visited[i] = false;
        }
    }
}

void BFS(int StartNum)
{
    // 실행하기전 초기화
    memset(Visited, false, sizeof(Visited));

    queue<int> nextNode;
    nextNode.push(StartNum);

    int count = 0;

    Visited[StartNum] = true;
    cout << "BFS : " << StartNum << " ";

    while (!nextNode.empty())
    {
        int num = nextNode.front();
        nextNode.pop();

        for (int i = 1; i < N + 1; i++)
        {
            if (Connection[num][i] && !Visited[i])
            {
                Visited[i] = true;
                nextNode.push(i);
                count++;

                cout << i << " ";
            }
        }
    }
}