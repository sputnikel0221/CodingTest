#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> connection[N + 1];
    int visited[N + 1] = {
        0,
    };

    int from, to;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> from;
        cin >> to;
        connection[from].push_back(to);
        connection[to].push_back(from);
    }

    // BFS
    queue<int> childNode;   
    childNode.push(1);      // 1부터 시작

    // 자식 노드를 타고 타고 돌면서, 본인으로 parent를 수정
    // 1부터 시작해서 레벨당 판별하기 떄문에, connection이 자식 부모
    // 상관없이 입력되었다고 해도, 항상 부모가 먼저 나오게 된다.
    while (!childNode.empty())
    {
        int parent = childNode.front();
        childNode.pop();
        
        for(int i=0;i<connection[parent].size();i++)  // 해당 노드와 연결된 노드 순회
        {
            int child = connection[parent][i]; // connection에서 parent->i인 것을 child로 둔다.
            if(!visited[child])
            {
                visited[child] = parent;    // visited[child]로 부모를 입력
                childNode.push(child);      
            }
        }
    }

    for (int i = 2; i < N + 1; i++) //2~N 인덱스
    {
        cout << visited[i] << "\n"; // 모든 부모를 출력
    }


    return 0;
}