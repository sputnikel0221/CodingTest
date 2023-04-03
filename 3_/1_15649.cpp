#include <iostream>
#include <stack>
using namespace std;

int N, M;

int ans[9];
bool visited[9];

void DFS(int);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    DFS(0);

    return 0;
}

void DFS(int count)
{
    // 1. 목적지인가?
    if (count == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    // 2. 연결된 곳을 순회
    for (int i = 1; i <= N; i++)
    {
        // 3. 갈 수 있는가?
        if (!visited[i])
        {

            // 5. 체크인
            ans[count] = i;
            visited[i] = true;

            // 4. 갈 수 있으면 간다.
            DFS(count + 1);

            // 6. 체크아웃
            visited[i] = false;
        }
    }
}