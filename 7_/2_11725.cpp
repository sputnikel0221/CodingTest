#include <iostream>
#include<vector>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력값들 받기
    int N;
    cin >> N;

    //bool connection[N+1][N+1]; //1~N인덱스 담을 수 있음
    //memset(connection, false, sizeof(connection));
    
    vector<int> connction[N+1];
    int visited[N+1] = {0, };
   

    int from, to;
    for (int i = 0; i < N-1; i++) //Tree라서 N-1`개`의 연결이 존재
    {
        cin >> from; 
        cin >> to;
        connction[from].push_back(to);
        connction[to].push_back(from);
    }

    // BFS
    queue<int> childNode;
    childNode.push(1);

    while (!childNode.empty())
    {
        int parent = childNode.front();
        childNode.pop();

        for (int i = 1; i < N + 1; i++) //1~N 인덱스
        {
            //if (connection[parent][i] && visited[i] == 0)
            if(connction[parent][i] && visited[i] == 0)
            {
                childNode.push(i);
                visited[i] = parent;
            }
        }
    }

    for (int i = 2; i < N + 1; i++) //2~N 인덱스
    {
        cout << visited[i] << "\n";
    }

    return 0;
}