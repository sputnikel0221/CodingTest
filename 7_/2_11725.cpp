#include <iostream>
#include <vector>
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
    
    vector<int> connection[N+1];
    int visited[N+1] = {0, };
   

    int from, to;
    for (int i = 0; i < N-1; i++) //Tree라서 N-1`개`의 연결이 존재
    {
        cin >> from; 
        cin >> to;
        connection[from].push_back(to);
        connection[to].push_back(from);
    }

    // BFS
    queue<int> childNode;
    childNode.push(1);

    while (!childNode.empty())
    {
        int parent = childNode.front();
        childNode.pop();
        
        for(int i=0;i<connection[parent].size();i++)
        {
            int child = connection[parent][i];
            if(!visited[child])
            {
                visited[child] = parent;
                childNode.push(child);
            }
        }
    }

    for (int i = 2; i < N + 1; i++) //2~N 인덱스
    {
        cout << visited[i] << "\n";
    }

    return 0;
}