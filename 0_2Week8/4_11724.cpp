#include <iostream>
#include <vector>

using namespace std;

int N, M;
int result = 0;
vector<int> v[1001];
bool visited[1001];

// 간단한 DFS, 백트래킹하지 않는 이유는, 어떻게든 연결이 되어있어서
// visited를 모두 순회할 수 있기 때문, 그리고 if-return문도 딱히 없다.
void DFS(int n)
{
    for(auto j : v[n])
    {
        if(!visited[j])
        {
            visited[j] = 1;
            DFS(j);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // 입력 (양방향)
    for(int i=0;i<M;i++)
    {
        int from, to;
        cin >> from >> to;

        v[from].push_back(to);
        v[to].push_back(from);
    }

    
    for(int i=1;i<N+1;i++)
    {
        // 연결된 것이 하나도 없는 경우 - 외딴섬
        // 굳이 visited 체크하지 않아도 된다.
        if(v[i].size()==0)
        {
            result++;
            continue;
        }

        // 연결된 것이 있는 경우, DFS돌며 visited체크
        for(auto j : v[i])
        {
            if(!visited[j])
            {
                visited[j] = 1;
                DFS(j);
                result++;
            }
        }
    }

    cout << result;

    return 0;   
}