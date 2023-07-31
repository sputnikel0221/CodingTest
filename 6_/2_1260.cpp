#include <iostream>
#include <queue>
#include <stack>
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

    //DFS
    stack<int> nextDNode;
    nextDNode.push(Start);


    while(!nextDNode.empty())
    {
        int num = nextDNode.top();
        nextDNode.pop();
        Visited[num] = true;

        for (int i = N; i > 0; i--)
        {
            if (Connection[num][i])
            {
                if(!Visited[i])
                {
                    cout << i << " ";
                    nextDNode.push(i);
                }
                
            }
        }
    }


    // BFS
    memset(Visited, false, sizeof(Visited));
    cout << "\n";

    queue<int> nextBNode;
    nextBNode.push(Start);


    Visited[Start] = true;
    cout << Start << " ";

    while (!nextBNode.empty())
    {
        int num = nextBNode.front();
        nextBNode.pop();

        for (int i = 1; i < N + 1; i++)
        {
            if (Connection[num][i] && !Visited[i])
            {
                Visited[i] = true;
                nextBNode.push(i);

                cout << i << " ";
            }
        }
    }

    return 0;
}


